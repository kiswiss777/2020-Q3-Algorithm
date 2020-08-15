#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_BOARD_SIZE (10)

char marbleBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

enum MoveDirection
{
    Default = 0,
    Up ,
    Down ,
    Left,
    Right
};

struct PositionInformation
{
    int currentBlueX ;
    int currentBlueY ;
    int currentRedX ;
    int currentRedY ;
};

void InitMarbleBoard()
{
    for( int verticalIndex = 0 ; verticalIndex < MAX_BOARD_SIZE ; ++verticalIndex)
    {
        for( int horizontalIndex = 0 ; horizontalIndex <MAX_BOARD_SIZE ; ++horizontalIndex)
        {
            marbleBoard[verticalIndex][horizontalIndex] = '#';
        }
    }
}

bool CheckMarblePosition( const int horizontalSize ,
                          const int verticalSize ,
                          const PositionInformation &posInfo )
{
    bool isValid = false;
    
    if( 0 < posInfo.currentRedY
       && verticalSize - 1 > posInfo.currentRedY)
    {
        isValid |= true;
    }
    
    if ( 0 < posInfo.currentRedX
        && horizontalSize - 1 > posInfo.currentRedX)
    {
        isValid |= true;
    }
    
    if( 0 < posInfo.currentBlueY
       && verticalSize - 1 > posInfo.currentBlueY)
    {
        isValid |= true;
    }
    
    if( 0 < posInfo.currentBlueX
       && horizontalSize - 1> posInfo.currentBlueX)
    {
        isValid |= true;
    }
    
    return isValid;
}

/* Function Role : InputHandler ( 입력 핸들러 )
 * Parameter * horizontalSize : Board horizontal Size
 * veriticalSize : Board Vertical Size
 * posInfor : Blue,Red Marble Information
 */
void InputMarbleBoard(const int horizontalSize ,
                      const int verticalSize ,
                      PositionInformation &posInfor)
{
    for( int horizontalIndex = 0 ; horizontalIndex < horizontalSize ; ++horizontalIndex)
    {
        for( int verticalIndex = 0 ; verticalIndex <verticalSize ; ++verticalIndex)
        {
            cin >> marbleBoard[verticalIndex][horizontalIndex] ;
            if( 'B' == marbleBoard[verticalIndex][horizontalIndex])
            {
                posInfor.currentBlueX = verticalIndex;
                posInfor.currentBlueY = horizontalIndex;
            }
            
            if( 'R' == marbleBoard[verticalIndex][horizontalIndex])
            {
                posInfor.currentRedX = verticalIndex;
                posInfor.currentRedY = horizontalIndex;
            }
        }
    }
}

void MoveMarble(const int horizontalSize ,
                const int verticalSize ,
                const MoveDirection directionFlag,
                PositionInformation &posInfo ,
                int answer)
{
    if( false == CheckMarblePosition(horizontalSize,verticalSize, posInfo))
    {
        return ;
    }
    
    switch ( directionFlag ) {
        case MoveDirection::Up:
            while( true )
            {
                
            }
            break;
        case MoveDirection::Down:
            break;
        case MoveDirection::Right:
            break;
        case MoveDirection::Left:
            break;
        default:
            cout << " Error Detected :: Not Exist Direction Flag\n"  ;
            return ;
            break;
    }
}

/* Complexity : 복잡도
 * Note: Input is not included in the complexity. : 입력 로직은 복잡도에  포함하지 않는다.
 *
 */
/* Solution method : 풀이 방법
 
 */

int main()
{
    InitMarbleBoard();
    /* Variable Description(변수 설명 : English , Korean )
     */
    int horizontalSize = 0;
    int verticalSize = 0;
    PositionInformation posInfo;
    
    cin >> verticalSize >> horizontalSize ;
    
    InputMarbleBoard(horizontalSize , verticalSize , posInfo);
    
}
