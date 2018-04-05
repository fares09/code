#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/*
FCI-Programming 1 -2018 - Assignment 2
Program Name : Cost of a long distant call , p.174 , number :1.
Last Modification Date 2/3/2018.
Author1 and ID and Group : Fares sayed hassan , 20170191 , 8.
Author2 and ID and Group : Alaa Ibrahem , 20170166 , 7.
Author3 and ID and Group : Amr Alaa , 20170187 , 7.
Author4 and ID and Group : Ali Samir , 20170172 ,7.
Teaching Assistant:
Purpose : To calculate the cost of long distant calls.
*/


int main()
{
    string day;
    string time;
    int timeMinutes;
    double timeHours;
    int nMinutes;
    double cost;
    string auxHours;
    string auxMinutes;

    cout << "Enter your call minutes :" << endl;
    cin >> nMinutes;
    cout << "Enter the day that you started the call in .\nIt should be abbreviated like:\n mo,tu,we,th,fr,sa and su ." << endl;
    cin >> day;
    cin.ignore();
    cout << "Enter the time you started the call at in 24 format like this 2:12 :" << endl;
    getline(cin,time);

    int i=0;
    while(time[i]!=':'){
        if(time[i]!=' '){
            auxHours+=time[i];
        }
        ++i;
    }

    for (int j=i+1; j<time.length();j++){

            if(time[j]!=' '){
                auxMinutes+=time[j];
            }

    }


    timeHours = stoi(auxHours);
    timeMinutes = stoi(auxMinutes);
    timeHours += timeMinutes / 60.0;




    if(( (tolower(day[0]) == 's') && (tolower(day[1]) == 'a') ) || ( (tolower(day[0]) == 's') && (tolower(day[1]) == 'u') )){
        cost=nMinutes * .15;
    }else {

        if(timeHours >= 8 && timeHours <= 18){
            cost=nMinutes * .40 ;

        }

        if ( (timeHours > 18 && timeHours <=24) || (timeHours >=0 && timeHours <8) ){

            cost = nMinutes * .25;
        }

    }

    cout << "The cost of your call is: " << cost << "$" <<endl;






    return 0;
}


