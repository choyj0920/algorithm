// baek 1009 분산처리
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void Result()
{
	// 테스트 케이스를 입력받는다.
	int t;
	scanf("%d", &t);

	// for 문 대신 테스트 케이스값을 1씩 빼면서 테스트하다보면
	// 어느 순간 0이 될때 while 루프를 빠지게 됨
	// for 문보다 간편한 방식
	while(t--){

		// 두 수를 입력받는다.
		long a, b;
		scanf("%ld %ld", &a, &b);

		// 첫번째 값을 넣고
		long result=a;

		// 모든 숫자는 4순환주기마다 100% 동일 숫자가 나온다 ( 연산속도 극적 향상 )
		b = b % 4 + 4;

		// 2번째 제곱부터 b 번째 제곱까지 a 값을 곱한다.
		for(long i=2;i<=b;++i) 
			// 곱하긴 곱하는데 그냥 곱하면 분명 범위 초과가 뜨므로
			// 문제의 목적은 몇번째 컴퓨터를 구하는 것이기 때문에 곱한 다음 
			// 10으로 나눈 몫만을 산출
			result=(result*a)%10;

		// 결과중 0이 나온 경우 0번째 컴퓨터는 없으므로 10번째 컴퓨터라고 명칭한다.
		if(result==0)result=10;

		// 최종 결과 출력
		printf("%ld\n", result);
	}
}

int main()
{
	Result();
	getchar(); getchar();
	return 0;
}