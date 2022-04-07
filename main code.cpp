#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
void bW_filter ();
int main() {
    int choice;
    cout<< "hello user, ";
    cout << " please enter name of image to process"<<endl;
     loadImage();
    cout  << "what filter would you like to do?\n"
          << "1. Black &white filter " << endl
          <<"2. invert filter" << endl
          << "3. merge filter"<< endl
          << "4. flip image" << endl
          <<"5. darken and lighten image" << endl
          << "6.rotate image"<< endl;
    cin >> choice;
    cin.ignore();
    if (choice == 1){
        //----------------- black and white filter--------------
        loadImage();
         bW_filter();
         saveImage();
         return 0;

    }

    else if (choice == 2){
        //-------------------- invert filter----------

    }
    else if (choice == 3 ){
        //------------------- merge filter-----------

        cout << "please enter name of image file to merge with: " ;

    }
    else if (choice == 4){
        int flip_choice;
        // ----------------flip image--------
        cout << " 1. flip horizontaly or 2. vertically";
        cin >> flip_choice;
        cin.ignore();
        if (flip_choice== 1){
            // ---------------flip horizontaly
        }
        else if (flip_choice == 2){
            // ------------flip vertically

        }
    }
    else if (choice == 5){
        int light_choice;
        //------------------ darken and lighten filter
        cout<< "do you want to 1. lighten or 2 . darken";
        cin >> light_choice;
        cin.ignore();
        if (light_choice==1){
            // ---------lighten
        }
        else if (light_choice==2){
            // -----------darken

        }
    }
    else if (choice == 6){
        // ------------------rotate image--------
        int rotate_choice;
        cout << "rotate 1. (90) \n 2. (180) \n 3. (360) degree";
        cin >> rotate_choice;
        cin.ignore();
        if (rotate_choice==1){
            // ----------rotate 90 degree
        }
        else if (rotate_choice==2){
            //------------ rotate 180 degree
        }
        else if (rotate_choice == 3) {
            //--------rotate  360 degree
        }
    }
}
 void loadImage () {
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

 void bW_filter () {
     for (int i = 0; i < SIZE; i++) {
         if (image[i][j] > 127)
             image[i][j] = 255;
         else
             image[i][j] = 0;
     }
 }



void saveImage () {
   char imageFileName[100];
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
