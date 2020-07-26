#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
#define MAX_CARD_COUNT 100
#define MAX_CARD_NUMBER 300000

/* Complexity : 복잡도
* Note: Input is not included in the complexity. : 입력 로직은 복잡도에     포함하지 않는다.
* for(N:countofCard - 2) * 3 = O(n^3)
*/

/* Solution method : 풀이 방법
 * 1. Remember the number with the smallest difference using absolute values. The difference between the input number and the difference value is output.
     : 절대 값을 이용하여 가장 적은 차이 값을 기억 후에 CardNumber(M) 과의 차이를 출력한다.
    -> Wrong Method Reason : If the sum exceeds M(cardNumber), an incorrect value is output.
     : 잘못된 방법의 이유 : 만약 합이 M을 넘는 경우 잘못된 결과를 출력
    E.G) M = 500 Card1 = 200 card2 = 200 card3 = 201 -> diff = 1
        output : 499 -> wrong
 * 2. After finding the sum, after comparing with the correct answer, if it is less than or equal, it is compared one more time and continuously updated before printing.
    : 합을 구한 후에 정답과 비교후에 작거나 같을 경우에만 한 번 더 비교 후 계속해서 최신화 후 출력
    -> Correct Method Reason : Complement the problem in #1.
    : 1번의 문제점을 보완
 */


int main()
{
    /* Complexity : 복잡도
     * Note: Input is not included in the complexity. : 입력 로직은 복잡도에     포함하지 않는다.
     * for(N:countofCard - 2) * 3 = O(n^3)
     */
    /* Variable Description(변수 설명 : English , Korean )
     * countOfCard = Input Card Count , 입력 : 카드 개수
     * nearestNumber = Answer ( near by cakdNum(M) ) 정답 ( M에 가까우 숫자 )
     * cardNumber = Input CardNum (M) 입력 : M 숫자
     * cardNumList = Input CardNum List : 입력 카드 숫자 목록
     * cardNumSum = Sum of 3 cards : 3개 카드의 합
     */
    int countOfCard = 0;
    int nearestNumber = 0;
    int cardNumber  = 0;
    int cardNumList[MAX_CARD_COUNT];
    int cardNumSum = 0;
    
    cin >> countOfCard ;
    cin >> cardNumber;
    
    for(int index = 0 ; index < countOfCard ; ++index)
    {
        cin >> cardNumList[index];
    }
    
    for(int firstIndex = 0 ; firstIndex < countOfCard - 2 ; ++firstIndex)
    {
        for( int seconIndex = firstIndex + 1 ; seconIndex < countOfCard - 1 ; ++seconIndex)
        {
            for( int thridIndex = seconIndex + 1; thridIndex < countOfCard; ++thridIndex)
            {
                cardNumSum = cardNumList[firstIndex] + cardNumList[seconIndex] + cardNumList[thridIndex];
                
                if( cardNumSum <= cardNumber )
                {
                    if( nearestNumber < cardNumSum )
                    {
                        nearestNumber = cardNumSum;
                    }
                }
            }
        }
    }
    cout << nearestNumber ;
    return 0;
}
