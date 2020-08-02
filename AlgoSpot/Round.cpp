#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_EMPLOYEE_COUNT 1000

/* Complexity : 복잡도
* Note: Input is not included in the complexity. : 입력 로직은 복잡도에  포함하지 않는다.
*
*/

/* Solution method : 풀이 방법

 */


int main()
{
    /* Variable Description(변수 설명 : English , Korean )
     */
    double employeesList[MAX_EMPLOYEE_COUNT];
    double employeesSalaryList[MAX_EMPLOYEE_COUNT];
    int testCount;
    cin >> testCount ;
    
    for(int testcase = 0 ; testcase < testCount ; ++testcase)
    {
        int employeesNumber = 0 ;
        int totalSalary = 0;
        cin >> employeesNumber >> totalSalary;
        for( int employeeIndex = 0 ; employeeIndex < employeesNumber ; ++ employeeIndex)
        {
            cin >> employeesList[employeeIndex];
            double tempSalary = ( employeesList[employeeIndex] / 100 ) * totalSalary ;
            tempSalary /= 100.0;
            tempSalary = ceil(tempSalary);
            employeesSalaryList[employeeIndex] = tempSalary * 100;
            // 직원들의 월급의 총합을 구한다.
            // 조정 하여야 하는 금액을 설정.
            // 금액대 범위 설정 e.g) 10~20% = 100만원
        }
    }
}
