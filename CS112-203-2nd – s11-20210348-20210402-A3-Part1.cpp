// FCAI – Programming 1 – 2022 - Assignment 3
// Program Name: PHOTOSHOP..cpp
// Last Modification Date: 4/19/2022
// Author1 and ID and Group: Moaz adly afify, 20210402, s11-s12
// Author2 and ID and Group: Mohamed fathi sayed, 20210348, s11-s12
// Author2 and ID and Group: bola maged Ramesses , 20210094, s19-s20
// Teaching Assistant: a.abdelmonem


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>



const int size = 256 ;
using namespace std;



unsigned char image[size][size];
unsigned char image2[size][size];
unsigned char image1[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char image4[SIZE][SIZE];
unsigned char SH_I[SIZE][SIZE];





void loadImage1();
void loadImage2();
void saveImage();
void Darken();
void Lighten();
void black_white();
void rotate();
void Flip_horizontal();
void Flip_vertical();
void merge();
void invert();
void Darken_or_lighten();
void flip();
void mirror();
void mirror_down();
void mirror_up();
void mirror_left();
void mirror_right();
void enlarge() ;
void enlarge_1() ;
void enlarge_2() ;
void enlarge_3() ;
void enlarge_4() ;
void lI ();
void sI ();
void action ();
void b();
void Sh_I();
void save_image_i () ;
void saveImage_2();
void detect();
void blur() ; 








int main(){
	char choice ;
	cout << "Ahlan ya user ya habibi ^_^ \n";
loadImage1();
cout << "Please select a filter to apply or 0 to exit: \n\n";
cout << "1- Black & White Filter\n";
cout << "2- Invert Filter\n";
cout << "3- Merge Filter\n";
cout << "4- Flip Image\n";
cout << "5- Rotate Image\n";
cout << "6- Darken and Lighten Image\n";
cout << "7- detect edges\n";
cout << "8- Enlarge\n";
cout << "9- Shrink\n";
cout << "A- Mirror\n";
cout << "B- Shuffle\n";
cout << "C- Blur\n";
cout << "your choice : ";
cin >> choice ;
while (  ! ( 48<= int(choice)  &&   int(choice) <= 57)  &&  !( choice == 'A' || choice ==  'a' || choice ==  'b'|| choice == 'B'  ||  choice =='c' || choice == 'C') ){
cout << "Please select a filter to apply or 0 to exit: \n\n";
cout << "1- Black & White Filter\n";
cout << "2- Invert Filter\n";
cout << "3- Merge Filter\n";
cout << "4- Flip Image\n";
cout << "5- Rotate Image\n";
cout << "6- Darken and Lighten Image\n";
cout << "7- detect edges\n";
cout << "8- Enlarge\n";
cout << "9- Shrink\n";
cout << "A- Mirror\n";
cout << "B- Shuffle\n";
cout << "C- Blur\n";
cout << "your choice : ";
cin >> choice ;
}




if(choice== '1'){
	black_white();
	saveImage();
	
}
else if (choice == '2'){
	invert();
	saveImage();
}
else if (choice == '3'){
loadImage2();
merge();
saveImage();
	
}
else if (choice == '4'){
	flip();
	saveImage();
	
}
else if (choice == '5'){
	int angle;
	cout << "\nenetr the angle of rotaion (90,180,270) :";
	cin >> angle;
	if(angle==90){
	
	rotate();
	saveImage();
	}
	else if (angle == 180){
		rotate();
		rotate();
		saveImage();
		
	}
	else if (angle == 270){
		rotate();
		rotate();
		rotate();
		saveImage();
	}
	while( angle != 270 &&  angle != 90  && angle!=180 ){
		cout << "\nenetr the angle of rotaion (90,180,270) :";
	cin >> angle;
	}
	
}
else if (choice == '6'){
	Darken_or_lighten();
	saveImage();
}
else if (choice == '7'){
	 detect();
	 saveImage_2();
}
else if (choice == '8'){
	enlarge();
	saveImage();
}
else if (choice == '9'){
	    Sh_I();
 save_image_i () ;
 }
else if(choice == 'A' ||  choice == 'a'){
	mirror();
	saveImage();	
	
}
else if(choice == 'B' || choice == 'b'){
	b();
}
else if(choice == 'C' || choice == 'c'){
	blur();
		saveImage();
}
else {
	// exit ass default
	cout << "bye bye ya user ya 7abibi (~_~) ";
}
	
	
	
	
	
	
	return 0;
}



void loadImage1() {
	
	
    char imageFileName[100];
    cout << "Please enter file name of the image to process: ";
	cin >> imageFileName ;
	
    strcat(imageFileName, ".bmp");
    
    while (readGSBMP(imageFileName, image)){
    	    cout << "Please enter file name of the image to process: ";
			cin >> imageFileName ;
	}
	//readGSBMP(imageFileName, image);
}

void loadImage2() {
	
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the second image file name: \n";
	cin >> imageFileName2 ;
    strcat(imageFileName2, ".bmp");

    while (readGSBMP(imageFileName2, image2)){
    	    cout << "Please enter file name of the second image to process: ";
			cin >> imageFileName2 ;
	}
}

void saveImage() {
    char imageFileName[100] ;

    // Get gray scale image target file name
    cout << "Enter the name of new image file name: ";
    cin >> imageFileName ;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName,image);
    cout << "done succefully .... check your files..^_^";
}

void saveImage_2() {
    char imageFileName[100] ;

    // Get gray scale image target file name
    cout << "Enter the name of new image file name: ";
    cin >> imageFileName ;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName,image2);
    cout << "done succefully .... check your files..^_^";
}

void black_white() {
  
}


void invert(){

	
}


void merge(){

}

void flip(){
	char choice_f ;
	cout << "\nenter 'V' to vertical flip or 'H' to horizontal flip: ";
	cin >> choice_f;
	if ( choice_f== 'V' || choice_f == 'v'){
		Flip_vertical();
	}
	else{
		Flip_horizontal();
	}

}

void rotate(){

	for(int i =0;i<size;++i){
	for(int j =i;j<size;++j){
				swap(image[i][j],image[j][i]);
				}
	}
	Flip_vertical();
}

void Darken_or_lighten(){
	
	char choice_D ;
	cout << "\nenter 'D' to darken the photo or 'L' to lighten the photo: ";
	cin >> choice_D;
	if (choice_D == 'D' || choice_D == 'd'){
		Darken();
	}
	else{
		Lighten();
	}
	

}


void Flip_vertical(){
	int	s=255;
	for(int row=0;row<size;row++){
	for(int col=255;col>128;col--){
		swap(image[row][col],image[row][col-s]);
		s=s-2;
	}
	s=255;
	}
}


void Flip_horizontal(){
int	s=255;
	for(int row=0;row<size;row++){
	for(int col=255;col>128;col--){
		swap(image[col][row],image[col-s][row]);
		s=s-2;
	}
	s=255;
	}
}



void Lighten(){
	
	for(int row=0;row<size;row++){
	for(int col=0;col<size;col++){
		image[row][col]= 1.5 * image[row][col];
			
		}
	}
	
}


void  Darken(){

	for(int row=0;row<size;row++){
	for(int col=0;col<size;col++){
		image[row][col]= 0.5 * image[row][col];
			
		}
	}
	
}





void mirror(){
	void mirror_down();
	void mirror_up();
	void mirror_left();
	void mirror_right();

	int D ;
	cout << "choose the side you want to mirror (1)right (2)left (3)upper (4)lower: ";
	cin >> D;
	
	if (D == 1){
		mirror_right();
	}
	else if (D == 3){
		mirror_up();
	}
	else if (D == 4){
	 	mirror_down();
	}
	else{
		 mirror_left();
	}
	
}

void mirror_right(){
	int	s=255;
	for(int row=0;row<size;row++){
	for(int col=255;col>128;col--){
		image[row][col-s] = image[row][col] ;
		s=s-2;
	}
	s=255;
	}

}


void mirror_left(){
	int	s=255;
	for(int row=0;row<size;row++){
	for(int col=255;col>128;col--){
		image[row][col] = image[row][col-s] ;
		s=s-2;
	}
	s=255;
	}
	}


void mirror_up(){
	int	s=255;
	for(int col=0;col<size;col++){
	for(int row=255;row>128;row--){
		image[row][col] = image[row-s][col] ;
		s=s-2;
	}
	s=255;
	}
}



void mirror_down(){
	
	
	int	s=255;
	for(int col=0;col<size;col++){
	for(int row=255;row>128;row--){
		 image[row-s][col] = image[row][col]  ;
		s=s-2;
	}
	s=255;
	}
}


void enlarge(){
	
	int D ;
	cout << "choose the quarter you want to inlarge 1--2\n                                       3--4 ";
	cin >> D;
	
	if (D == 1){
		enlarge_1();
	}
	else if (D == 2){
		enlarge_2();
	}
	else if (D == 4){
	 	enlarge_4();
	}
	else{
		enlarge_3();
	}
}





void enlarge_1(){
	int s1=size-1 , s2=size-2;
	for(int row=0;row<127;row++){
		for(int col=127;col>0; col--){
			image[row][s1] = image[row][col];
			image[row][s2] = image[row][col];
			s1-=2;
			s2-=2;
		}
		s1=size-1 ;
		s2=size-2;
	}
	
		s1=size-1 ;
		 s2=size-2;

	for(int col=0;col<size;col++){
		for(int row=127;row>=0; row--){
			image[s1][col] = image[row][col];
			image[s2][col] = image[row][col];
			s1-=2;
			s2-=2;
		}
		s1=size-1 ;
		s2=size-2;
	}
}



void enlarge_2(){
	
	int s1=0 , s2= 1;
	for(int row=0;row<127;row++){
		for(int col=127;col<size; col++){
			image[row][s1] = image[row][col];
			image[row][s2] = image[row][col];
			s1+=2;
			s2+=2;
		}
		s1=0 ;
		s2=1;
	}
	
		s1=size-1 ;
		 s2=size-2;

	for(int col=0;col<size;col++){
		for(int row=127;row>=0; row--){
			image[s1][col] = image[row][col];
			image[s2][col] = image[row][col];
			s1-=2;
			s2-=2;
		}
		s1=size-1 ;
		s2=size-2;
	}
}


void enlarge_3(){
	
	int s1=size-1 , s2=size-2;
	for(int row=127;row<size;row++){
		for(int col=127;col>0; col--){
			image[row][s1] = image[row][col];
			image[row][s2] = image[row][col];
			s1-=2;
			s2-=2;
		}
		s1=size-1 ;
		s2=size-2;
	}
	
		s1=0 ;
		 s2=1;

	for(int col=0;col<size;col++){
		for(int row=127;row<size; row++){
			image[s1][col] = image[row][col];
			image[s2][col] = image[row][col];
			s1+=2;
			s2+=2;
		}
		s1=0;
		s2=1;
	}
}



void enlarge_4(){
		int s1=0 , s2= 1;
	for(int row=127;row<size;row++){
		for(int col=127;col<size; col++){
			image[row][s1] = image[row][col];
			image[row][s2] = image[row][col];
			s1+=2;
			s2+=2;
		}
		s1=0 ;
		s2=1;
	}
	
	s1=0 ;
		 s2=1;

	for(int col=0;col<size;col++){
		for(int row=127;row<size; row++){
			image[s1][col] = image[row][col];
			image[s2][col] = image[row][col];
			s1+=2;
			s2+=2;
		}
		s1=0;
		s2=1;
	}
}

void b(){
    lI();
    action();
    sI();
}


void lI () {
    char file_name[100];

    // Get the name of the gray image
    cout << "Enter the source image file name: ";
    cin >> file_name;

    // Add (.bmp) to the name of the image and load it
    strcat (file_name, ".bmp");
    readGSBMP(file_name, image);
}

void sI () {
    char file_name[100];

    // Get the type of the image that he want
    cout << "Enter the target image file name: ";
    cin >> file_name;

    // Add (.bmp) to the name of the image and load it
    strcat (file_name, ".bmp");
    writeGSBMP(file_name, image);
}

void action() {
    int q,w,e,r;
    cout << "enter the order of quarters: ";
    cin >> q>>w>>e>>r;
    for (int i = 0; i < SIZE/2; i++ ) {
        for (int j = 0; j < SIZE / 2; j++) {
            image1[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 127, z =0 ; j < SIZE; j++, z++) {
            image2[i][z] = image[i][j];
        }
    }
    for (int i = 127 , z=0 ; i < SIZE; i++ ,z++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image3[z][j] =  image[i][j];
        }
    }
    for (int i = 127,z=0; i < SIZE; i++,z++) {
        for (int j = 127,x=0; j < SIZE ; j++,x++) {
            image4[z][x] =  image[i][j];
        }
    }
    for (int i = 0; i < SIZE/2 ; i++) {
        for (int j = 0; j < SIZE/2 ; j++) {
            if (q==1)
                image[i][j] =image1[i][j];
            if (q==2)
                image[i][j] =image2[i][j];
            if (q==3)
                image[i][j] =image3[i][j];
            if (q==4)
                image[i][j] =image4[i][j];
        }
    }
    for (int i = 0  ; i < SIZE/2; i++) {
        for (int j = 127, z=0; j < SIZE ; j++ ,z++) {
            if (w==1)
                image[i][j] =image1[i][z];
            if (w==2)
                image[i][j] =image2[i][z];
            if (w==3)
                image[i][j] =image3[i][z];
            if (w==4)
                image[i][j] =image4[i][z];
        }
    }
    for (int i = 127 , z=0; i < SIZE; i++ ,z++) {
        for (int j = 0; j < SIZE / 2; j++) {
            if (e==1)
                image[i][j] =image1[z][j];
            if (e==2)
                image[i][j] =image2[z][j];
            if (e==3)
                image[i][j] =image3[z][j];
            if (e==4)
                image[i][j] =image4[z][j];
        }
    }
    for (int i = 127 ,z=0; i < SIZE; i++,z++) {
        for (int j = 127 ,x=0; j < SIZE ; j++,x++) {
            if (r==1)
                image[i][j] =image1[z][x];
            if (r==2)
                image[i][j] =image2[z][x];
            if (r==3)
                image[i][j] =image3[z][x];
            if (r==4)
                image[i][j] =image4[z][x];
        }
    }




}



void Sh_I(){
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0; j<SIZE;j++){
            SH_I[i][j] = 255;
        }
    }
    int choise;
    cout<<"choose Shrink size:\n[1]1/2\n[2]1/3\n[3]1/4\n=>";
    cin>>choise;


    if (choise == 1){

        for(int i=0;i<SIZE;i++)
        {
            for(int j=0; j<SIZE;j++){
                SH_I[i/2][j/2]=image[i][j];
            }
        }
    }
    else if (choise == 2){
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0; j<SIZE;j++){
                SH_I[i/3][j/3]=image[i][j];
            }
        }
    }
    else if (choise == 3){
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0; j<SIZE;j++){
                SH_I[i/4][j/4]=image[i][j];
            }
        }
    }
}


void save_image_i () {
    char imageFileName[100];

    // Get the type of the image that he want
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add (.bmp) to the name of the image and load it
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, SH_I);
}

void detect(){
	for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {



        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;
    }
  }
  for(int k = 1; k < SIZE; k++)
  {
  	for(int l = 1; l < SIZE; l++)
	  {
	  	image2[k][l] = (image[k][l+1] + image[k][l-1] + image[k+1][l] + image[k-1][l]) - 4 * image[k][l];
	  }
  }
  for(int row=0;row<size;++row){
	for(int col=0;col<size;++col){
	image2[row][col]=255-image2[row][col];
}
}
  
  }

void blur(){
	for(int i =1;i<SIZE;i++){
         for(int j=1;j<SIZE;j++){
         image[j][i]=(image[j-1][i-1]+image[j-1][i]+image[j+1][i]+image[j][i-1]+image[j][i+1]+image[j-1][i+1]+
         image[j+1][i-1]+image[j+1][i+1]+image[j-1][i-2]+image[j][i-2]+image[j+1][i-2]+image[j-1][i+2]+
         image[j][i+2]+image[j+1][i+2]+image[j-2][i-2]+image[j-2][i-1]+image[j-2][i]+image[j-2][i+1]+
         image[j-2][i+2]+image[j-2][i+3]+image[j+2][i-2]+image[j+2][i-1]+image[j+2][i]+image[j+2][i+1]+
         image[j+2][i+2]+image[j+3][i+2]+image[j+2][i+4]+image[j-1][i+3]+image[j][i+3]+image[j+1][i+3]+
         image[j-2][i+4]+image[j-1][i+4]+image[j][i+4]+image[j+1][i+4]+image[j+3][i-2]+image[j+3][i-1]+
         image[j+3][i]+image[j+3][i+1]+image[j+3][i+2]+image[j+3][i+3]+image[j+3][i+4]+image[j+4][i-2]+
         image[j+4][i-1]+image[j+4][i]+image[j+4][i+1]+image[j+4][i+2]+image[j+4][i+3]+image[j+4][i+4])/47;
        
        }
}
}





