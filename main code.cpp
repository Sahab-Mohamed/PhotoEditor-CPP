#include <iostream>
using namespace std;
int main() {
    int choice;
    cout<< "hello user, "
    << "what filter would you like to do?\n"
    << "1. Black &white filter " << endl
    <<"2. invert filter" << endl
    << "3. merge filter"<< endl
    << "4. flip image" << endl
    <<"5. darken and lighten image" << endl
    << "6.rotate image"<< endl;
    cin >> choice;
    cin.ignore();
    if (choice == 1){
        // black and whiter filter
    }
    
        else if (choice == 2){
       // invert filter
           
       }
        else if (choice == 3 ){
            // merge filter
            
            cout << "please enter name of image file to merge with: " ;
            
        }
        else if (choice == 4){
    int flip_choice;
            // flip image
            cout << " 1. flip horizontaly or 2. vertically";
            cin >> flip_choice;
            cin.ignore();
            if (flip_choice== 1){
                // flip horizontaly
            }
            else if (flip_choice == 2){
                // flip vertically
            
        }
}
        else if (choice == 5){
            int light_choice;
            // darken and lighten filter
            cout<< "do you want to 1. lighten or 2 . darken";
            cin >> light_choice;
            cin.ignore();
            if (light_choice==1){
                // lighten
            }
            else if (light_choice==2){
                 // darken
                    
                }
            }
        else if (choice == 6){
            // rotate image
            int rotate_choice;
            cout << "rotate 1. (90) \n 2. (180) \n 3. (360) degree";
            cin >> rotate_choice;
            cin.ignore();
            if (rotate_choice==1){
                // rotate 90 degree
            }
            else if (rotate_choice==2){
                 // rotate 180 degree
                }
            else if (rotate_choice == 3) {
                //rotate  360 degree
            }
        }
}
