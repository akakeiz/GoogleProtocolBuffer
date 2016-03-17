#include "stdafx.h"
#include "Tester.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>


namespace NProtobuf {

using namespace std;
using namespace google;

void
Tester::RUN( int count )
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


	auto start	= chrono::system_clock::now();

	for( int i=0; i<count; i++ )
	{
		protobuf::io::ArrayOutputStream os( outputBuf, bufsize );
		src_person.SerializeToZeroCopyStream( &os );	
	}
	
	auto end	= chrono::system_clock::now();
	
	auto duration	= chrono::duration_cast<chrono::milliseconds>( end - start );

	cout	<< "ASIO result : "	<< duration.count()	<< " (ms)" << endl;
}




}