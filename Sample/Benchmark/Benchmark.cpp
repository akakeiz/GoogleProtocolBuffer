// Benchmark.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

