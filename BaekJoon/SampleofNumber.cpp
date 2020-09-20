#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define MAX_SEAT_NUMBER (40)

int seatArray[MAX_SEAT_NUMBER + 1];
int vipArray[MAX_SEAT_NUMBER + 1];

/* Complexity : 복잡도
 * Note: Input is not included in the complexity. : 입력 로직은 복잡도에 포함하지 않는다.
 * O(n)
 */

/* Solution method : 풀이 방법
 * 1. Calculate by calculating the starting number using the error according to the decimal point value.
    -> 소수점 값에 따른 오차를 이용하여 시작 숫자를 구하여 계산 진행.
 */


bool CheckPossibleNumber(const float inputPercentage ,
                         const float checkPercentage)
{
    bool isPossible = false;
    int tempInputPercentage = inputPercentage * 1000;
    int tempCheckPercentage = checkPercentage * 1000;
    
    if( 0 == tempInputPercentage % tempCheckPercentage )
    {
        isPossible = true;
    }
    
    return isPossible;
}


inline double GetThreeDecimalPalces(const float inputNum)
{
    double demicalNumber = floor(inputNum * 1000.0f + 0.5 ) / 1000.0f ;
    return demicalNumber;
}

inline double GetStartSampleNumber(const float inputNum)
{
    float result = inputNum;
    float divideNumber = inputNum;
    int tempNum = 0;
    
    if( 1 > inputNum)
    {
        tempNum = inputNum * 1000;
    }
    else
    {
        divideNumber = inputNum - floor(inputNum);
        tempNum = divideNumber *  1000;
    }
    
    if( 0 != tempNum % 1000)
    {
        result = 100 / ( divideNumber + 0.0005 );
    }
    else if( 0 != tempNum % 100)
    {
        result = 100 / ( divideNumber + 0.005);
    }
    else if( 0 != tempNum % 10)
    {
        result = 100 / (divideNumber + 0.05);
    }
    else
    {
        result = 1;
    }
    
    return floor(result);
}

int main()
{
    int testCase = 0 ;
    cin >> testCase;
    for( int testIndex = 0 ; testIndex < testCase ; ++testIndex )
    {
        float percenTage = 0 ;
        cin >> percenTage;
        float numberSample = GetStartSampleNumber(percenTage);
        
        while( true )
        {
            if( true == CheckPossibleNumber( percenTage , GetThreeDecimalPalces(100.0 / numberSample) ) )
            {
                break;
            }
            numberSample++;
        }
        
        cout << numberSample <<endl;
    }
    return 0;
}
