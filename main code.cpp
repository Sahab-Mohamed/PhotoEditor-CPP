// fci - programming 1 - 2022 - assigment 3
//program name : photoshop.cpp
// author 1 : Rana ayman barakat alsakka id : 20210511
//author 2 : sahab mohammed abd el rahman id : 20210518
// author 3 : mohanad hesham id : 20210414
// teaching assistant : s5 - s6


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "cmake-build-debug/bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
void rotate_image_90();
void rotate_image_180();
void rotate_image_270();
void loadImage ();
void loadImage2 ();
void saveImage ();
void bW_filter ();
void flip_image_h();
void flip_image_v();
void invert_image();
void merge_function();
void mirror_half_image();
void detect_edges();
void shrink_image();
void enlarge_image ();
void shuffle_image();
void blur_image ();
void save_to_file ();
int main() {
    string choice;
    cout << "hello user, ";
    cout << "what filter would you like to do?\n"
         << "1. Black &white filter " << endl
         << "2. invert filter" << endl
         << "3. merge filter" << endl
         << "4. flip image" << endl
         << "5. darken and lighten image" << endl
         << "6.rotate image" << endl
         << "7 . detect image edges" << endl
         << "8. enlarge image" << endl
         << " 9. shrink image " << endl
         << " a. mirror 1/2 image" << endl
         << " b. shuffle image " << endl
         << " c . blur image" << endl
         << "s . save image to a file" << endl;
    cin >> choice;
    cin.ignore();
    if (choice == "1" ){
        //----------------- black and white filter--------------
        loadImage();
        bW_filter();
        saveImage();
        return 0;

    } else if (choice == "2") {
        //-------------------- invert filter----------
        loadImage();
        invert_image();
        saveImage();
        return 0;

    } else if (choice == "3") {
        //------------------- merge filter-----------
        loadImage();
        loadImage2();
        merge_function();
        saveImage();
        cout << "please enter name of image file to merge with: ";

    } else if (choice == "4") {
        int flip_choice;
        // ----------------flip image--------
        cout << " 1. flip horizontaly or 2. vertically";
        cin >> flip_choice;
        cin.ignore();
        if (flip_choice == 1) {
            // ---------------flip horizontaly
            loadImage();
            flip_image_h();
            saveImage();
            return 0;
        } else if (flip_choice == 2) {
            // ------------flip vertically
            loadImage();
            flip_image_v();
            saveImage();
            return 0;

        }
    } else if (choice == "5") {
        int light_choice;
        //------------------ darken and lighten filter
        cout << "do you want to 1. lighten or 2 . darken";
        cin >> light_choice;
        cin.ignore();
        if (light_choice == 1) {
            // ---------lighten
        } else if (light_choice == 2) {
            // -----------darken

        }
    } else if (choice == "6") {
        // ------------------rotate image--------
        int rotate_choice;
        cout << "rotate 1. (90) \n 2. (180) \n 3. (270) degree";
        cin >> rotate_choice;
        cin.ignore();
        if (rotate_choice == 1) {
            // ----------rotate 90 degree
            loadImage();
            rotate_image_90();
            saveImage();
            return 0;

        } else if (rotate_choice == 2) {
            //------------ rotate 180 degree
            loadImage();
            rotate_image_180();
            saveImage();
            return 0;

        } else if (rotate_choice == 3) {
            //--------rotate  270 degree
            loadImage();
            rotate_image_270();
            saveImage();
            return 0;
        }
    }
    /*else if (choice == "7") {
        //-------------------- detect image edges----------
        loadImage();
        detect_edges();
        saveImage();
        return 0;
        */
        /* } else if (choice == "8") {
             //-------------------- enlarge image----------
             loadImage();
             enlarge_image();
             saveImage();
             return 0;
         }*/
        /* else if (choice == "9") {
            //-------------------- shrink image----------
            loadImage();
            shrink_image();
            saveImage();
            return 0;

        }
        */

    else if (choice == "a") {
        //-------------------- mirror 1/2 image----------
        loadImage();
        mirror_half_image();
        saveImage();
        return 0;
    }
}
void loadImage () {
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
void loadImage2 () {
    char image2FileName[100];
    cout << "Enter the source image file name: ";
    cin >> image2FileName;
    strcat(image2FileName, ".bmp");
    readGSBMP(image2FileName, image2);
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
void flip_image_h(){
    for (int i = 0; i<  SIZE/2 ; i++){
        for (int y = 0; y < SIZE ; y++ )
            swap(image[i][y], image[SIZE - i - 1][SIZE - y - 1]);
    }

}
void flip_image_v () {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            image[i][j] = image[i][500-j];
    }
}
void invert_image(){

    for(int i = 0; i<SIZE; i++)
        for(int j = 0; j<SIZE; j++)
            image[i][j] = 255 - image [i][j];


}
void merge_function() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            image[i][j] = (image[i][j] + image2[i][j]) / 2;
}
void mirror_half_image(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            image[i][j] = image[i][255 - j];
    }

}
void detect_edges(){

}
void shrink_image(){

}
void enlarge_image(){

}
void save_to_file (){

}
void shuffle_image () {

}
void blur_image (){

}

