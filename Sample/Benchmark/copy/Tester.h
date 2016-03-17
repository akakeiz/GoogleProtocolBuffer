#pragma once


namespace NCopy {

class Tester
{
public:
	static	void	RUN( int count );


	struct AddressBook
	{
		char name[ 10 ];
		char email[ 20 ];
		char phone[ 32 ];
		int id;			
	};
};


}