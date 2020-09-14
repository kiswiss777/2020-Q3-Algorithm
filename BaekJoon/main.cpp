#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_SEAT_NUMBER (40)

int seatArray[MAX_SEAT_NUMBER + 1];
int vipArray[MAX_SEAT_NUMBER + 1];

/* Complexity : 복잡도
 * Note: Input is not included in the complexity. : 입력 로직은 복잡도에 포함하지 않는다.
 *
 */

/* Solution method : 풀이 방법
 * 1. The number of cases that can be made by moving from one's seat has the Fibonacci rule. Approach using that rule.
    -> 자기 자리에서 이동 하여 만들 수 있는 경우의 수는 피보나치 규칙을 가진다. 해당 규칙을 이용하여 접근.
   2. Multiply the number of cases based on the vip reserved seat. -> Because they play differently based on boundaries.
    -> vip 지정석을 경계로 경우의 수를 구하여 곱한다. -> 경계를 기반으로 다르게 놀기 때문이다.
   3. Finally, multiply by the number of vips. -> The same reason as #2.
    -> 마지막으로 vip 수 만큼 곱해준다. -> 2번과 같은 이유이다.
 */

void CalculateNumberOfCase(int personCount )
{
    seatArray[0] = seatArray[1] = 1;
    for(int index = 2; index <= personCount ; ++ index)
    {
        seatArray[index] = seatArray[index - 1] + seatArray[index - 2];
    }
}

int GetResult(int vipCount , int personCount)
{
    int result = 1;
    for( int vipIndex = 1 ; vipIndex <= vipCount ; ++vipIndex )
    {
        result *= seatArray[vipArray[vipIndex] - vipArray[vipIndex -1] -1];
    }
    result *= seatArray[personCount - vipArray[vipCount]];
    return result;
}

int main()
{
    int personCount = 0 ;
    cin >> personCount ;
    CalculateNumberOfCase(personCount);
    
    int vipCount = 0 ;
    cin >> vipCount ;
    for( int vipIndex = 1 ; vipIndex <= vipCount ;++vipIndex)
    {
        int vipNumber = 0 ;
        cin >> vipNumber;
        vipArray[vipIndex] = vipNumber;
    }
    cout<< GetResult(vipCount , personCount) << endl;
    
    return 0;
}
