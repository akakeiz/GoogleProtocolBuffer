#include "stdafx.h"
#include "Tester.h"

#include <iostream>
#include <chrono>

namespace NCopy {

using namespace std;

void
Tester::RUN( int count )
{
	AddressBook stBook;
	stBook.id	= 10;
	strcpy_s<10>( stBook.name, "alice" );
	strcpy_s<20>( stBook.email, "alice@anydomai.com" );
	strcpy_s<32>( stBook.phone, "123-0101" );

	
	char * outputBuf	= new char[ sizeof(AddressBook) ];

	auto start	= chrono::system_clock::now();

	for( int i=0; i<count; i++ )
	{
		//memcpy( outputBuf, & stBook, sizeof(AddressBook) );
		AddressBook temp;
		temp	= stBook;
	}
	
	auto end	= chrono::system_clock::now();
	
	auto duration	= chrono::duration_cast<chrono::milliseconds>( end - start );

	cout	<< "MemCopy result : "	<< duration.count()	<< " (ms)" << endl;
}




}