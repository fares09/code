#include <iostream>
#include <string>
using namespace std;
/*
FCI-Programming 1 -2018 - Assignment 2
Program Name : gross pay and net pay advanced calculator.
Last Modification Date 3/3/2018.
Author1 and ID and Group : Fares sayed hassan , 20170191 , 8.
Author2 and ID and Group : Alaa Ibrahem , 20170166 , 7.
Author3 and ID and Group : Amr Alaa , 20170187 , 7.
Author4 and ID and Group : Ali Samir , 20170172 ,7.
Teaching Assistant:
Purpose : To calculate the gross pay and the net pay within given weeks.

*/

int main()
{


    const double FIRST_40_PAY_RATE = 16.78;
    const double OVER_PAY_RATE = FIRST_40_PAY_RATE * 1.5;
    double nHours ;
    int nWeeks ;
    int WeeksCounter=1;
    double ndependents;
    double grossPay=0;
    double socialSecurityTax;//6% from gross pay.
    double federalIncomTax;//14% from gross pay.
    double stateIncomeTax;//5%.
    const double UNION_DUES=10;//subtract per week.
    const double HEALTH_INSURANCE=35;//subtract from gross pay if dependents are 3 or more.
    double netPay=0;// pay after subtracting taxes .

    cout << "Enter the number of weeks:" << endl;
    cin >> nWeeks;
    cout << "Enter your number of dependents:" << endl;
    cin >> ndependents;

    while(nWeeks-- > 0){
        cout << "Enter number of hours your worked on week " << WeeksCounter++ << endl;
        cin >> nHours ;
        grossPay += (nHours <= 40 ? FIRST_40_PAY_RATE *nHours : FIRST_40_PAY_RATE * 40 + OVER_PAY_RATE *(nHours-40))
        netPay += grossPay -UNION_DUES;

    }


    socialSecurityTax = grossPay * (6.0/100);
    cout << socialSecurityTax << " social " << endl;
    federalIncomTax = grossPay * (14.0/100);
    stateIncomeTax = grossPay * (5.0 /100);
    netPay = grossPay - (socialSecurityTax + federalIncomTax + stateIncomeTax + (ndependents >= 3 ? HEALTH_INSURANCE : 0) );

    cout << "Your gross pay is: " << grossPay << endl;
    cout << "The federal income tax is: " << federalIncomTax << endl;
    cout << "The social income tax is: " << socialSecurityTax << endl;
    cout << "The state income tax is: " << stateIncomeTax << endl;
    cout << "The Union dues are: " << UNION_DUES * nWeeks << endl;
    cout << "The health insurance is " << HEALTH_INSURANCE << endl;
    cout << "Your net pay is: " << netPay << endl;




    return 0;
}
