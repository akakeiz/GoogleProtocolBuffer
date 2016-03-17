// BasicTest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

using namespace std;
using namespace google;

int _tmain(int argc, _TCHAR* argv[])
{
	tutorial::Person src_person;
	src_person.set_id( 41 );
	src_person.set_name( "alice" );
	src_person.set_email( "alice@anydomain.com" );
	
	tutorial::Person::PhoneNumber * phone0	= src_person.add_phone();
	phone0->set_number( "123-0101" );
	phone0->set_type( tutorial::Person_PhoneType_MOBILE );

	tutorial::Person::PhoneNumber * phone1	= src_person.add_phone();
	phone1->set_number( "456-0202" );
	phone1->set_type( tutorial::Person_PhoneType_HOME );

	int bufsize	= src_person.ByteSize();
	char * outputBuf	= new char[ bufsize ];

	// ���ۿ� ����ȭ
	protobuf::io::ArrayOutputStream os( outputBuf, bufsize );
	src_person.SerializeToZeroCopyStream( &os );

	// ���ۿ��� ������ȭ
	protobuf::io::ArrayInputStream is( outputBuf, bufsize );
	tutorial::Person dst_person0;
	dst_person0.ParseFromZeroCopyStream( &is );

	// Message ��ü���� ����������
	string name	= dst_person0.name();
	int id	= dst_person0.id();
	for( int i=0; i<dst_person0.phone_size(); i++ )
	{
		const tutorial::Person_PhoneNumber & phone	= dst_person0.phone( i );
		tutorial::Person_PhoneType phone_type = phone.type();
		string phone_number	= phone.number();
	}

	// ���Ͽ� ����ȭ
	const char* test_filename = "person.txt";
	fstream ofs(test_filename, ios::out | ios::trunc | ios::binary);
	src_person.SerializeToOstream(&ofs);
	ofs.close();


	// ���Ͽ��� ������ȭ
	fstream ifs(test_filename, ios::in | ios::binary);
	tutorial::Person dst_person1;
	dst_person1.ParseFromIstream(&ifs);
	ifs.close();


	// �޸� ����
	delete [] outputBuf;
	outputBuf = NULL;
	protobuf::ShutdownProtobufLibrary();
	return 0;
}

