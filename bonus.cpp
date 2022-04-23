// fci - programming 1 - 2022 - assigment 3
//program name : photoshop.cpp
// author 1 : Rana ayman barakat alsakka id : 20210511
//author 2 : sahab mohammed abd el rahman id : 20210158
// author 3 : mohanad hesham id : 20210414
// teaching assistant : s5 - s6
// bonus

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "cmake-build-debug/bmplib.cpp"
using namespace std;
unsigned char colored[256][256][3];
unsigned char colored2[256][256][3];
char imageFileName[100];
char image2FileName[100];
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
void detect_edges();
void enlarge_image1();
void enlarge_image2();
void enlarge_image3();
void enlarge_image4();
void shuffle_image();
void blur_image ();
void lighten_image();
void darken_image();
void save_to_file ();
void shuffle();
void mirror_half_image1();
void mirror_half_image2();
void mirror_half_image3();
void mirror_half_image4();
void shrink_image1();
void shrink_image2();
void shrink_image3();

int main() {
    string choice;
    cout << "hello user, ";
    cout << "what filter would you like to do?\n"
         << "1. Black &white filter " << endl
         << "2. invert filter" << endl
         << "3. merge filter" << endl
         << "4. flip image" << endl
         << "5. darken and lighten image" << endl
         << "6. rotate image" << endl
         << "7. detect image edges" << endl
         << "8. enlarge image" << endl
         << "9. shrink image " << endl
         << "a. mirror 1/2 image" << endl
         << "b. shuffle image " << endl
         << "c. blur image" << endl
         << "s. save image to a file" << endl;
    cin >> choice;
    cin.ignore();
    if (choice == "1") {
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
            loadImage();
            lighten_image();
            saveImage();
        } else if (light_choice == 2) {
            // -----------darken
            loadImage();
            darken_image();
            saveImage();

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
    } else if (choice == "7") {
        //-------------------- detect image edges----------
        loadImage();
        detect_edges();
        saveImage();
        return 0;
    } else if (choice == "8") {
//-------------------- enlarge image----------
        int enlarge_choice;
        cout << " which quarter to enlarge? \n 1 , 2 , 3 , 4 \n";
        cin >> enlarge_choice;
        cin.ignore();
        if (enlarge_choice == 1) {
            loadImage();
            enlarge_image1();
            saveImage();
            return 0;
        } else if (enlarge_choice == 2) {
            loadImage();
            enlarge_image2();
            saveImage();
            return 0;
        } else if (enlarge_choice == 3) {
            loadImage();
            enlarge_image3();
            saveImage();
            return 0;
        } else if (enlarge_choice == 4) {
            loadImage();
            enlarge_image4();
            saveImage();
            return 0;
        } else { cout << "please enter number from 1 to 4"; }
    } else if (choice == "9") {
        //-------------------- shrink image----------
        int shrink_choice;
        cout << "choose shrink to : \n 1) 1/2 \n 2) 1/3 \n 3) 1/4\n";
        cin >> shrink_choice;
        //-------------------- shrink 1/2 image
        if (shrink_choice == 1) {
            loadImage();
            shrink_image1();
            saveImage();
            return 0;
        }
            //-------------------- shrink 1/3 image
        else if (shrink_choice == 2) {
            loadImage();
            shrink_image2();
            saveImage();
            return 0;
        }
            //-------------------- shrink 1/4 image
        else if (shrink_choice == 3) {
            loadImage();
            shrink_image3();
            saveImage();
            return 0;
        }
    } else if (choice == "a") {
//-------------------- mirror 1/2 image----------
        int mirror_choice;
        cout << " choose \n 1. 1/2 left\n 2. 1/2 right\n 3 .1/2 upper\n 4. 1/2 lower" << endl;
        cin >> mirror_choice;
        cin.ignore();
        if (mirror_choice == 1) {
            // ---------------mirror 1/2 image left
            loadImage();
            mirror_half_image1();
            saveImage();
            return 0;
        } else if (mirror_choice == 2) {
            // ------------mirror 1/2 image right
            loadImage();
            mirror_half_image2();
            saveImage();
            return 0;
        } else if (mirror_choice == 3) {
            // ------------mirror 1/2 image up
            loadImage();
            mirror_half_image3();
            saveImage();
            return 0;
        } else if (mirror_choice == 4) {
            // ------------mirror 1/2 image down
            loadImage();
            mirror_half_image4();
            saveImage();
            return 0;
        }
    } else if (choice == "b") {
        loadImage();
        shuffle();
        saveImage();
    }
        else if (choice == "c") {
            loadImage();
            blur_image();
            saveImage();
        } else if (choice == "s") {
            save_to_file();
            return 0;
        }

}
void loadImage() {
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, colored);

}
void loadImage2() {
    char image2FileName[100];
    cout << "please enter name of image file to merge with: : ";
    cin >> image2FileName;
    strcat (image2FileName, ".bmp");
    readRGBBMP(image2FileName, colored2);

}
void bW_filter() {
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            for(int k=0 ;k<3 ; k++)
            {
                if (colored[i][j][k]>=127)
                    colored[i][j][k]=255;
                else
                    colored[i][j][k]=0;
            }

        }

    }
}
    void saveImage() {
        char imageFileName[100];
        cout << "Enter the target image file name: ";
        cin >> imageFileName;
        strcat(imageFileName, ".bmp");
        writeRGBBMP(imageFileName, colored);

    }

void rotate_image_90() {
    for (int i = 0; i < (SIZE); i++){
        for (int j =i+1; j< (SIZE); j++) {
            for(int c=0 ;c<3 ;c++)
            {
                swap(colored[i][j][c],colored[j][i][c]);
            }

        }
    }
    for (int i = 0; i < SIZE; i++ ){
        for (int j = 0; j < SIZE/2; j += 1){
            for(int c=0 ; c<3 ;c++)
            {
                swap(colored[j][i][c], colored[SIZE-j-1][i][c]);
            }
        }
            }
        }

void rotate_image_180() {
    for (int i = 0; i < SIZE / 2; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int c = 0; c < 3; ++c) {
                swap(colored[i][j][c], colored[SIZE - i - 1][SIZE - j - 1][c]);
            }  }           }       }
void rotate_image_270() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = i; j < SIZE; ++j) {
            for (int c = 0; c < 3; c++) {

                swap(colored[i][j][c], colored[j][i][c]);

            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            for (int c = 0; c < 3; c++) {
            swap(colored[i][j][c], colored[j][SIZE - 1 - j][c]);
        }
    }}
}
void flip_image_h(){
    for (int i = 0; i<  SIZE/2 ; i++){
        for (int y = 0; y < SIZE ; y++ ) {
            for (int c = 0; c < 3; c++) {
                swap(colored[i][y][c], colored[SIZE - i - 1][SIZE - y - 1][c]);
            }
        }}
}
void flip_image_v () {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c < 3; c++) {
                colored[i][j][c] = colored[i][500 - j][c];
            }
        }
    }
}
void invert_image(){

    for(int i = 0; i<SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c < 3; c++) {
                colored[i][j][c] = 255 - colored[i][j][c];
            }
        }
    }
        writeRGBBMP( "test.bmp",colored);

}


void merge_function() {
   
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c < 3; c++) {
                colored[i][j][c] = (colored[i][j][c] + colored2[i][j][c]) / 2;
            }
        }}
    
    }
void mirror_half_image1() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c < 3; c++) {
                colored[i][j][c] = colored[i][255 - j][c];
            }
        }
    }
}
void mirror_half_image2() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c <3; c++) {
                colored[i][255 - j][c] = colored[i][j][c];
            }
        }
    }
}
    void mirror_half_image3() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int c = 0; c < 3; c++) {

                    colored[i][j][c] = colored[SIZE - 1 / 255 - i][j][c];
                }
            }
        }
    }
    void mirror_half_image4() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++){
                for (int c = 0; c < 3; c++) {
                colored[SIZE - 1 / 255 - i][j][c] = colored[i][j][c];
        }
    }}}

void detect_edges() {
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
            for (int c = 0; c < 3; c++) {
            if ((colored[i][j][c]-colored[i][j+9][c]>25))
            {colored[i][j][c]=0;}
            else
                colored [i][j][c] =255;
        }
    }
}}

void enlarge_image1() {
    unsigned char temp[256][256][3];
    for(int i=0 ,k=0 ; i<256/2 ; i++ , k+=2)
    {
        for(int j=0,n=0;j<256/2 ; j++ ,n+=2)
        {
            for (int c = 0; c < 3; c++) {
            temp[k][n][c]=colored[i][j][c];
            temp[k+1][n][c]=colored[i][j][c];
            temp[k][n+1][c]=colored[i][j][c];
            temp[k+1][n+1][c]=colored[i][j][c];
        }
    }}
    for(int i=0 ; i<256 ; i++){
        for(int j=0 ; j<256 ; j++){
            for (int c = 0; c < 3; c++) {
            colored[i][j][c] = temp[i][j][c];
        }
    }
}}

void enlarge_image2 () {
    unsigned char temp[256][256][3];

    for (int i = 0, k = 0; i < 256 / 2; i++, k += 2) {
        for (int j = 256 / 2, n = 0; j < 256; j++, n += 2) {
            for (int c = 0; c < 3; c++) {
                temp[k][n][c] = colored[i][j][c];
                temp[k + 1][n][c] = colored[i][j][c];
                temp[k][n + 1][c] = colored[i][j][c];
                temp[k + 1][n + 1][c] = colored[i][j][c];
            }
        }
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                for (int c = 0; c < 3; c++) {
                    colored[i][j][c] = temp[i][j][c];
                }
            }
        }
    }
}
void enlarge_image3(){
    unsigned char temp[256][256][3];
    for(int i=256/2 ,k=0 ; i<256 ; i++ , k+=2)
    {
        for(int j=0,n=0;j<256/2 ; j++ ,n+=2)
        {
            for (int c = 0; c < 3; c++) {
            temp[k][n][c]=colored[i][j][c];
            temp[k+1][n][c]=colored[i][j][c];
            temp[k][n+1][c]=colored[i][j][c];
            temp[k+1][n+1][c]=colored[i][j][c];
        }
    }}
    for(int i=0 ; i<256 ; i++){
        for(int j=0 ; j<256 ; j++){
            for (int c = 0; c < 3; c++) {
            colored[i][j][c] = temp[i][j][c];
        }
    }}}
void enlarge_image4() {
    unsigned char temp[256][256][3];

    for (int i = 256 / 2, k = 0; i < 256; i++, k += 2) {
        for (int j = 256 / 2, n = 0; j < 256; j++, n += 2) {
            for (int c = 0; c < 3; c++) {
                temp[k][n][c] = colored[i][j][c];
                temp[k + 1][n][c] = colored[i][j][c];
                temp[k][n + 1][c] = colored[i][j][c];
                temp[k + 1][n + 1][c] = colored[i][j][c];
            }
            for (int i = 0; i <= 256; i++) {
                for (int j = 0; j <= 256; j++) {
                    for (int c = 0; c < 3; c++) {

                        colored[i][j][c] = temp[i][j][c];
                    }
                }
            }
        }
    }
}
  void save_to_file () { loadImage();
    saveImage();}


void shuffle() {
    loop:
    int x1, x2, x3, x4;
    cout << "Enter the order of the shuffle that you want" << endl;
    cin >> x1 >> x2 >> x3 >> x4;
    unsigned char temp[256][256][3];
    if (x1 == 1) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {

                    temp[i][j][c] = colored[i][j][c];
                }
            }
        }
    } else if (x1 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i][j][c] = colored[i][j + 128][c];
                }
            }
        }
    } else if (x1 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i][j][c] = colored[i + 128][j][c];
                }
            }
        }
    } else if (x1 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i][j][c] = colored[i + 128][j + 128][c];
                }
            }
        }
    } else {
        cout << "please try again another numbers" << endl;
        goto loop;
    }
    if (x2 == 1) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i][j + 128][c] = colored[i][j][c];
                }
            }
        }
    } else if (x2 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i][j + 128][c] = colored[i][j + 128][c];
                }
            }
        }
    } else if (x2 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i][j + 128][c] = colored[i + 128][j][c];
                }
            }
        }
    } else if (x2 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i][128][c] = colored[i + 128][j + 128][c];
                }
            }
        }
    } else {
        cout << "please try again another numbers" << endl;
        goto loop;
    }
    if (x3 == 1) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i + 128][j][c] = colored[i][j][c];
                }
            }
        }
    } else if (x3 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i + 128][j][c] = colored[i][j + 128][c];
                }
            }
        }
    } else if (x3 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[i + 128][j][c] = colored[i + 128][j][c];
                }
            }
        }
    } else if (x3 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int c = 0; c < 3; c++) {
                    temp[+128][j][c] = colored[i + 128][j + 128][c];
                }
            }
        }
        if (x4 == 1) {
            for (int i = 0; i < 128; i++) {
                for (int j = 0; j < 128; j++) {
                    for (int c = 0; c < 3; c++) {
                        temp[i + 128][j + 128][c] = colored[i][j][c];
                    }
                }
            }
        } else if (x4 == 2) {
            for (int i = 0; i < 128; i++) {
                for (int j = 0; j < 128; j++) {
                    for (int c = 0; c < 3; c++) {
                        temp[i + 128][j + 128][c] = colored[i][j + 128][c];
                    }
                }
            }
        } else if (x4 == 3) {
            for (int i = 0; i < 128; i++) {
                for (int j = 0; j < 128; j++) {
                    for (int c = 0; c < 3; c++) {
                        temp[i + 128][j + 128][c] = colored[i + 128][j][c];
                    }
                }
            }
        } else if (x4 == 4) {
            for (int i = 0; i < 128; i++) {
                for (int j = 0; j < 128; j++) {
                    for (int c = 0; c <3; c++) {
                        temp[i + 128][j + 128][c] = colored[i + 128][j + 128][c];
                    }
                }
            }
        } else {
            cout << "please try again another numbers" << endl;
            goto loop;
        }
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                for (int c = 0; c < 3; c++) {
                    colored[i][j][c] = temp[i][j][c];
                }
            }
        }
    }
}
void blur_image (){
    double average;

    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            for (int k =0 ; k <3; k++){
                int sum = 0;
                sum = colored[i ][j ][k] + colored[i ][j+1][k] + colored[i][j + 2][k] + colored[i+1][j][k] + colored[i+1][j+1][k] +colored[i+1][j +2][k] + colored[i +2][j ][k] + colored[i + 2][j+1][k] + colored[i + 2][j + 2][k];
                average = (sum / 9);
                colored[i][j][k] = average;
            }

        }
    }
}
}

void lighten_image() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c < 3; c++) {
                if (colored[i][j][c]<= 127) {
                    colored[i][j][c] = colored[i][j][c] + 70;
                } else if (colored[i][j][c] <= 255) {
                    colored[i][j][c] = (colored[i][j][c]);
                }
            }
        }
    }
}
}
void darken_image() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c < 3; c++) {
                colored[i][j][c] = colored[i][j][c] / 2;
            }
        }
    }
}
}

void shrink_image1() {
    unsigned char temp[256][256][3];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c < 3; c++) {
                temp[i][j][c] = 255;
            }}
    }
    for (int i = 0, k = 0; k < 128; i += 2, k++) {
        for (int j = 0, z = 0; z < 128; j += 2, z++) {
            for (int c = 0; c < 3; c++) {
                temp[k][z][c] = colored[i][j][c];
                temp[k + 1][z][c] = colored[i][j][c];
                temp[k][z + 1][c] = colored[i][j][c];
                temp[k + 1][z + 1] [c]= colored[i][j][c];
            }}
    }
    for (int i = 0; i <= SIZE; i++) {
        for (int j = 0; j <= SIZE; j++) {
            for (int c = 0; c < 3; c++) {
                colored[i][j][c] = temp[i][j][c];
            }
        }
    }}
}
void shrink_image3()  {
    unsigned char temp[256][256][3];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c < 3; c++) {
            temp[i][j][c] = 255;
        }}
    }
    for (int i = 0, k = 0; k < 64; i += 4, k++) {
        for (int j = 0, z = 0; z < 64; j += 4, z++) {
            for (int c = 0; c < 3; c++) {
            temp[k][z][c] = colored[i][j][c];
            temp[k + 1][z][c] = colored[i][j][c];
            temp[k][z + 1][c] = colored[i][j][c];
            temp[k + 1][z + 1] [c]= colored[i][j][c];
        }}
    }
    for (int i = 0; i <= SIZE; i++) {
        for (int j = 0; j <= SIZE; j++) {
            for (int c = 0; c < 3; c++) {
            colored[i][j][c] = temp[i][j][c];
        }
    }
}}
}void shrink_image2() {
  unsigned char temp[256][256][3];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int c = 0; c < 3; c++) {
            temp[i][j][c] = 255;
        }
    }}
    for (int i = 0, k = 0; k < 86; i += 3, k++) {
        for (int j = 0, z = 0; z < 86; j += 3, z++) {
            for (int c = 0; c < 3; c++) {
            temp[k][z][c] = colored[i][j][c];
            temp[k + 1][z][c] = colored[i][j][c];
            temp[k][z + 1] [c]= colored[i][j][c];
            temp[k + 1][z + 1][c] = colored[i][j][c];
        }
    }}
    for (int i = 0; i <= SIZE; i++) {
        for (int j = 0; j <= SIZE; j++) {
            for (int c = 0; c < 3; c++) {
            colored[i][j][c] = temp[i][j][c];
        }
    }
}}

}
