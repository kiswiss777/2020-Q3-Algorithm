#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define MAX_ALPHABET_COUNT (16)
/* Variable Description(변수 설명 : English , Korean )
* alphabetLength : L, 문자 길이
* alphabetCount : C , 문자 개수
* resultAlphabet : makePassword , 암호
* alphabetList : inputAlphabet , 입력받은 문자들의 모임
*/

int alphabetLength = 0;
int alphabetCount = 0;
char resultAlphabet[MAX_ALPHABET_COUNT];
char alphabetList[MAX_ALPHABET_COUNT] ;

/* Complexity : 복잡도
 * Note: Input is not included in the complexity. : 입력 로직은 복잡도에 포함하지 않는다.
 * O(n!) = recursive method
 */

/* Solution method : 풀이 방법
 * 1. After sorting the letters, a combination of letters is obtained from the first alphabet. The method of finding the combination uses a recursive method.
    -> 문자를 정렬 후 첫 번째 알파벳부터 문자의 조합을 구한다. 해당 조합을 구하는 방식은 재귀 방식을 이용한다.
 */

bool CheckPassword()
{
    /* Variable Description(변수 설명 : English , Korean )
     * consonant : consonant , 자음
     * vowel : vowel , 모음
     */
    int consonant = 0;
    int vowel = 0 ;
    bool result = false;
    
    for( int index = 0 ; index < alphabetLength ; ++ index )
    {
        char currentAlphabet = resultAlphabet[index];
        
        if (   currentAlphabet == 97
            || currentAlphabet == 101
            || currentAlphabet == 105
            || currentAlphabet == 111
            || currentAlphabet == 117)
        {
            vowel++;
        }
        else
        {
            consonant++;
        }
        
        if(   vowel >= 1
           && consonant >=2)
        {
            result = true;
            break;
        }
    }
    return result;
}

void DepthFirstSearch(int alpahbetIndex , int depth )
{
    if( depth == alphabetLength)
    {
        if( true == CheckPassword())
        {
            for( int index = 0 ; index < alphabetLength ; ++ index)
            {
                cout << resultAlphabet[index];
            }
            cout << endl;
        }
        
        return ;
    }
    
    for( int index = alpahbetIndex ; index < alphabetCount ; ++index )
    {
        resultAlphabet[depth] = alphabetList[index];
        DepthFirstSearch(index + 1, depth + 1);
    }
}

int main()
{
    cin >> alphabetLength >> alphabetCount;
    
    for( int alphabetIndex = 0 ; alphabetIndex < alphabetCount ; ++ alphabetIndex)
    {
        cin >> alphabetList[alphabetIndex];
    }
    sort(alphabetList , alphabetList + alphabetCount);
    DepthFirstSearch(0,0);
    return 0;
}
