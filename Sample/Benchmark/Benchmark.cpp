// Benchmark.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include "protobuf/Tester.h"
#include "copy/Tester.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int testCount	= 2000000;

	NCopy::Tester::RUN( testCount );
	NProtobuf::Tester::RUN( testCount );
	
	return 0;
}

