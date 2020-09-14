#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_BOARD_SIZE (50)
string board[MAX_BOARD_SIZE] ;

/* Complexity : 복잡도
 * Note: Input is not included in the complexity. : 입력 로직은 복잡도에 포함하지 않는다.
 * O( N^2 ) = for * 2
 */

/* Solution method : 풀이 방법
 * 1. It was calculated by dividing the white and black patterns through %2.
    ->%2 연산을 통해 White 와 Black을 구분하여 계산하였다.
 */

int GetMinValue( int leftValue , int rightValue)
{
    if( leftValue > rightValue)
    {
        return rightValue;
    }
    else
    {
        return leftValue;
    }
}

int GetCheseCount(int horizontalIndex,  int verticalIndex)
{
    int whiteCount = 0;
    int blackCount = 0;
    for(int verIndex = verticalIndex ; verIndex < verticalIndex + 8 ; ++verIndex)
    {
        for( int horiztonIndex = horizontalIndex ; horiztonIndex < horizontalIndex + 8 ; ++horiztonIndex)
        {
            if( 0 == (verIndex + horiztonIndex) % 2 )
            {
                if('B' == board[horiztonIndex][verIndex])
                {
                    whiteCount++;
                }
                else
                {
                    blackCount++;
                }
            }
            else
            {
                if( 'B' == board[horiztonIndex][verIndex] )
                {
                    blackCount++;
                }
                else
                {
                    whiteCount++;
                }
            }
        }
    }
    return GetMinValue(whiteCount, blackCount);
}

int main()
{
    /* Variable Description(변수 설명 : English , Korean )
     * horizontalSize = Input N ( Horitizontal Sie ) : 입력 N ( 수평 사이즈 = 즉 Y )
     * verticalSize = Input M ( Vertical Size ) : 입력 M ( 수직 사이즈 = 즉 X )
     * countOfSquare = Answer Minimum Count of Colcor : 결과 가장 작은 정사각형의 개수
     */
    int horizontalSize = 0;
    int verticalSize = 0 ;
    int countOfSquare =  200914;
    
    cin >> horizontalSize >> verticalSize;
    
    for( int index = 0 ; index < horizontalSize ; ++index )
    {
        cin >> board[index];
    }
    
    for(int horitizonIndex = 0 ; horitizonIndex < horizontalSize - 7; ++horitizonIndex)
    {
        for(int verIndex = 0 ; verIndex < verticalSize - 7 ; ++verIndex)
        {
            countOfSquare = GetMinValue(countOfSquare, GetCheseCount(horitizonIndex, verIndex));
        }
    }
    
    cout << countOfSquare << endl;
    return 0;
}
