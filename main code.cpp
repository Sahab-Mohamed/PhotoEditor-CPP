#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "cmake-build-debug/bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];
void rotate_image_90();
void rotate_image_180();
void rotate_image_270();
void loadImage ();
void saveImage ();
void bW_filter ();
int main() {
    int choice;
    cout<< "hello user, ";
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
        // ----------------flipp image--------
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
        cout << "rotate 1. (90) \n 2. (180) \n 3. (270) degree";
        cin >> rotate_choice;
        cin.ignore();
        if (rotate_choice == 1){
            // ----------rotate 90 degree
            loadImage();
            rotate_image_90();
            saveImage();
            return 0;

        }

        else if (rotate_choice==2){
            //------------ rotate 180 degree
            loadImage();
            rotate_image_180();
            saveImage();
            return 0;

        }
        else if (rotate_choice == 3) {
            //--------rotate  270 degree
            loadImage();
            rotate_image_270();
            saveImage();
            return 0;
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
    long avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
             avg += image[i][j];
         }
     }
     avg /= (SIZE*SIZE);
     for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
             if (image[i][j] > avg)
                 image[i][j] = 255;
             else
                 image[i][j] = 0;
         }
     }
 }

     void saveImage() {
         char imageFileName[100];
         cout << "Enter the target image file name: ";
         cin >> imageFileName;
         strcat(imageFileName, ".bmp");
         writeGSBMP(imageFileName, image);
     }

     void rotate_image_90() {
         for (int i = 0; i < SIZE; i++) {

             for (int j = i; j < SIZE; j++) {
                 int temp = image[i][j];
                 image[i][j] = image[j][i];
                 image[j][i] = temp;
             }
         }


         for (int i = 0; i < SIZE; i++) {

             for (int j = 0; j < SIZE / 2; j++) {
                 int temp = image[i][j];
                 image[i][j] = image[i][SIZE - 1 - j];
                 image[i][SIZE - 1 - j] = temp;
             }
         }
     }
void rotate_image_180() {
    for (int i = 0; i < SIZE / 2; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            swap(image[i][j], image[SIZE - i - 1][SIZE - j - 1]);
        }}}
void rotate_image_270() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = i; j < SIZE; ++j) {
            swap(image[i][j], image[j][i]);

        }
    }
    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE / 2; j++) {
            swap(image[i][j], image[j][SIZE - 1 - j]);
        }
    }



        }


