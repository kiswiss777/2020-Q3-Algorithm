#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_WATERLEAK_LOCATE 1001

/* Complexity : 복잡도
* Note: Input is not included in the complexity. : 입력 로직은 복잡도에     포함하지 않는다.
* std::sort(quick sort) => O( NLogN ) + CalculateTapeCount => O(N) = O(NLogN) + O(N) = O(NLogN)
*/

/* Solution method : 풀이 방법
 * 1.Sort the list of leaks. Because, in order to finish the required number of tapes in N times, it is convenient to have water leaks in order.
   물이 새는 곳의 위치를 정렬한다. 왜냐하면 물이새는 곳이 차례대로 정렬이 되어 있을 경우에는 N번 만에 정답을 찾을수 있기 때문이다.
 * 2.Specifies the range that can be covered by a single tape. We need -1 because we need 0.5 margins on each side.
   하나의 테이프로 커버 할 수 있는 범위를 지정한다. 양쪽으로 0.5씩 여유가 필요하기 때문에 -1를 해주어야 한다.
 * 3.If it is not possible to cover from the position where the tape was started, re-specify the range of the tape.
   테이프를 붙이기 시작한 위치로 부터 커버가 불가능할 경우에는 테이프의 범위를 다시 지정한다.
 */


int main()
{
    /* Variable Description(변수 설명 : English , Korean )
     * waterLeakCount = water leak Count , 물이 새는 곳의 개수
     * tapeLength = tape length , 테이프의 길이
     * tapeCount = need to tape count , 필요한 테이프의 개수
     * waterLeakLocateList = water leak locate list , 물이새는 위치의 목록
     * rangeRecoverable = Coverage with one tape , 하나의 테이프로 커버가 가능한 범위.
     */
    int waterLeakCount = 0;
    int tapeLength = 0 ;
    int tapeCount = 0 ;
    int waterLeakLocateList[MAX_WATERLEAK_LOCATE];
    int rangeRecoverable = 0 ;
    cin >> waterLeakCount >> tapeLength;

    if( tapeLength < 1 )
    {
        rangeRecoverable = MAX_WATERLEAK_LOCATE;
    }
    
    for ( int index = 0 ; index < waterLeakCount ; ++ index)
    {
        cin >> waterLeakLocateList[index];
    }
    
    sort(waterLeakLocateList , waterLeakLocateList+waterLeakCount);
    
    for( int index = 0 ; index <waterLeakCount ; ++ index)
    {
        int startLocate = waterLeakLocateList[index];
        
        if( rangeRecoverable < startLocate)
        {
            tapeCount++;
            rangeRecoverable = startLocate + tapeLength - 1;
        }
    }
    
    cout << tapeCount;
}
