/*
FCI-Programming 1 -2018 - Assignment 2
Program Name : caesar cipher.
Last Modification Date 3/3/2018.
Author1 and ID and Group : Fares sayed hassan , 20170191 , 8.
Author2 and ID and Group : Alaa Ibrahem , 20170166 , 7.
Author3 and ID and Group : Amr Alaa , 20170187 , 7.
Author4 and ID and Group : Ali Samir , 20170172 ,7.
Teaching Assistant:
Purpose : ciphering and deciphering using caesar way.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

char ciepher (char character, int shift);
char deciepher(char character, int shift);

int main()
{


    int choice ;

    cout << "hello user! what do you want?" << endl;


     string message;
     string ciepheredMessage;
     string deciepheredMessage;

     int shifts;
     while(true){
            cout << "\npress 1 for ciephering\n";
            cout << "press 2 for deciephering\n";
            cout << "press any other number to exit\n";
            cin >> choice;

    //ciephering
            if(choice == 1){

                cout << "enter number of shifts:\n";
                cin >> shifts;
                cin.ignore();
                cout << "enter your message:\n";
                getline(cin,message);




                for(int i=0;i<message.length();i++){
                    if(message[i]==' '){
                        ciepheredMessage+=' ';

                    }else{
                        ciepheredMessage+=ciepher(message[i],shifts);

                    }
                }//end of ciephering loop
                cout << "ciepher: "<< ciepheredMessage;



            // Deciephering.
            }else if(choice == 2){
                cout << "enter number of shifts:\n";
                cin >> shifts;
                cin.ignore();
                cout << "enter your message:\n";
                getline(cin,message);


                for(int i=0;i<message.length();i++){
                    if(message[i]==' '){
                        deciepheredMessage+=' ';

                    }else{
                        deciepheredMessage+=deciepher(message[i],shifts);

                    }
                }//end of deciephering loop.
                cout << "deciepher: " << deciepheredMessage;


            }else{
                break;
            }
     }

    return 0;
}// end of main().

char ciepher(char character ,int shift){
    int assciNumberOfCeipherc=0;
    int assciToConvertc=0;

    if(character>='a' && character<='z'){
         assciNumberOfCeipherc=character+shift;
         assciToConvertc=assciNumberOfCeipherc-(assciNumberOfCeipherc >'z'?26:0);
        return (char(assciToConvertc));


    }else if(character>='A' && character<='Z'){
         assciNumberOfCeipherc=character+shift;
         assciToConvertc=assciNumberOfCeipherc-(assciNumberOfCeipherc >'Z'?26:0);
        return (char(assciToConvertc));
    }else{
         assciNumberOfCeipherc=character+shift;
         assciToConvertc=assciNumberOfCeipherc;
        return (char(assciToConvertc));


    }

}
char deciepher(char character,int shift){
    int assciNumberOfDeceipherd=0;
    int assciToConvertd=0;

    if(character>='a' && character<='z'){
         assciNumberOfDeceipherd=character-shift;
         assciToConvertd=assciNumberOfDeceipherd+(assciNumberOfDeceipherd <'a'?26:0);
        return (char(assciToConvertd));


    }else if(character>='A' && character<='Z'){
        assciNumberOfDeceipherd=character-shift;
        assciToConvertd=assciNumberOfDeceipherd+(assciNumberOfDeceipherd <'A'?26:0);
        return (char(assciToConvertd));
    }else{
         assciNumberOfDeceipherd=character-shift;
         assciToConvertd=assciNumberOfDeceipherd;
        return (char(assciToConvertd));


    }


}



