#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define EXIST_CABBAGE (1)
#define MAX_CABBAGE_FIELD_SIZE (51)

int cabbageField[MAX_CABBAGE_FIELD_SIZE][MAX_CABBAGE_FIELD_SIZE];
bool visitFlag[MAX_CABBAGE_FIELD_SIZE][MAX_CABBAGE_FIELD_SIZE];

/* Complexity : 복잡도
 * Note: Input is not included in the complexity. : 입력 로직은 복잡도에     포함하지 않는다.
 * for * 2 = O(n^2)
 */

/* Solution method : 풀이 방법
 * 1. Set a visit flag after checking the cabbages connected at the locations of all the cabbage plates.
      : 모든 배추판의 위치에서 연결되는 배추를 확인 후 방문 플래그를 설정한다.
 */

void InitCabbageField()
{
    for( int x = 0 ;  x< MAX_CABBAGE_FIELD_SIZE ; ++x)
    {
        for( int y = 0 ; y< MAX_CABBAGE_FIELD_SIZE ; ++y)
        {
            cabbageField[x][y] = 0;
            visitFlag[x][y] = false;
            
        }
    }
}

void InputPlantingCabbage(const int cabbageFieldVerticalSize,
                          const int cabbageFieldHorizontalsize,
                          const int cabbageCount)
{
    for(int cabbageIndex = 0 ; cabbageIndex < cabbageCount ; ++cabbageIndex)
    {
        int cabbageX = 0;
        int cabbageY = 0 ;
        cin >> cabbageX >> cabbageY ;
        cabbageField[cabbageX][cabbageY] = 1;
    }
}

void CalculateEarthWorm(const int checkPointX , const int checkPointY )
{
    if( 0 > checkPointY
       || 0 > checkPointX)
    {
        return ;
    }
    if( EXIST_CABBAGE == cabbageField[checkPointX][checkPointY]
       && false == visitFlag[checkPointX][checkPointY])
    {
        visitFlag[checkPointX][checkPointY] = true;
        CalculateEarthWorm(checkPointX + 1, checkPointY );
        CalculateEarthWorm(checkPointX, checkPointY + 1);
        CalculateEarthWorm(checkPointX - 1, checkPointY );
        CalculateEarthWorm(checkPointX, checkPointY - 1);
    }
}


int CalculateController(int cabbageFieldVerticalSize,
                         int cabbageFieldHorizontalsize)
{
    int needWormCount = 0;
    for( int x = 0 ; x < cabbageFieldHorizontalsize ; ++x)
    {
        for( int y = 0 ; y < cabbageFieldVerticalSize ; ++y)
        {
            if( EXIST_CABBAGE == cabbageField[x][y]
            && false == visitFlag[x][y])
            {
                CalculateEarthWorm(x, y);
                needWormCount ++ ;
            }
        }
    }
    return needWormCount;
}

int main()
{
    /* Solution method : 풀이 방법
     * 1.
     * 2.
     */
    
    int testCase = 0 ;
    cin >> testCase;
    
    for( int testIndex = 0 ; testIndex < testCase ; ++ testIndex)
    {
        InitCabbageField();
        int cabbageFieldVerticalSize = 0;
        int cabbageFieldHorizontalsize = 0;
        int cabbageCount = 0 ;
        cin >> cabbageFieldHorizontalsize >> cabbageFieldVerticalSize >> cabbageCount;
        InputPlantingCabbage(cabbageFieldVerticalSize, cabbageFieldHorizontalsize , cabbageCount);
        cout << CalculateController(cabbageFieldVerticalSize,cabbageFieldHorizontalsize) << endl;
    }
    
    return 0;
}
