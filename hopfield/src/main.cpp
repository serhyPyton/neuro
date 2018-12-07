/*kohonen(self organised) maps - delevoped by SerhyPyton*/
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <opencv2/imgproc/imgproc.hpp>
#include <sstream>

using namespace cv;
using namespace std;

int read_img(char *name, int n, vector<Mat>& pic)
{
    Mat img;
    Mat image;
    img = imread(name);
    cvtColor( img, image, CV_RGB2GRAY);
//    Mat src = imread("threshold.png", IMREAD_GRAYSCALE);
    Mat dst;

// Set threshold and maxValue
    double thresh = 0;
    double maxValue = 255;

// Binary Threshold
    threshold(image, dst, thresh, maxValue, THRESH_BINARY);
    pic[n]=dst;
    return 0;
}


void classify(vector<vector<double>>& weight, vector<int>& pics, Mat& pic, vector<int>& out_pics, int t){
for(int j=0;j<128*128;j++){
        int d=0;
        for(int i=0;i<128*128;i++){
            d+=weight[j][i]*pics[i];
        }
        if (d>=0) out_pics[j]=1;
        else out_pics[j]=-1;
    }

for(int j=0;j<128*128;j++)
    pics[j]=out_pics[j];

  //  Mat cpic;
  //  pic.copyTo(cpic);
    for(int j=0;j<128*128;j++){
        pic.at<uchar>((int)(j/128-1),j%128-1)=125*out_pics[j]+125;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE );     // Create a window for display.
    imshow( "Display window", pic );                   // Show our image inside it.
    waitKey(0);
    cvDestroyWindow("Display window");
    stringstream ss;
    ss<<"weight_"<<t<<".png";
    imwrite(ss.str(),pic );

cout<<"second itter"<<endl;
}

int main(int argc, char* argv[])
{
    //init
    vector<Mat> pic(8);
    read_img("images/c.png", 0, pic);
    read_img("images/g.png", 1, pic);
    read_img("images/m.png", 2, pic);
    read_img("images/n.png", 3, pic);
    read_img("images/s.png", 4, pic);
    read_img("images/n1.png", 5, pic);
    read_img("images/c1.png", 6, pic);
    read_img("images/c2.png", 7, pic);
    vector<vector<int>> pics(8, vector<int>(128*128));
    vector<vector<int>> out_pics(2, vector<int>(128*128));
  //  vector<int> neurons (128*128);
    vector<vector<double>> weight(128*128, vector<double>(128*128));
    for(int j=0;j<128*128;j++){     //generated weights
        for(int i=0;i<128*128;i++){
            weight[j][i]=0;
    }
    }
    for(int k=0; k<8; k++){
        for(int j=0; j<128; j++){
            for(int i=0;i<128;i++)
                if ((int)pic[k].at<uchar>(j,i)==255)
                pics[k][128*j+i]=1;//(int)pic[k].at<uchar>(j,i);
                else
                pics[k][128*j+i]=-1;//(int)pic[k].at<uchar>(j,i);
        }
    }

for(int k=0;k<5;k++){
    for(int j=0;j<128*128;j++){     //generated weights
        for(int i=0;i<128*128;i++){
            weight[j][i]+=pics[k][j]*pics[k][i];
        }
        weight[j][j]=0;
    }
    }

    for(int j=0;j<128*128;j++){     //generated weights
        for(int i=0;i<128*128;i++){
         //   weight[j][i]=weight[j][i]/(128.*128.);
    }
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE );     // Create a window for display.
    imshow( "Display window", pic[5] );                   // Show our image inside it.
    waitKey(0);
cout<<"norm"<<endl;
    /////////////////
    //for pics not in learned sequence 5-th

cout<<"::M"<<endl;
classify(weight, pics[2], pic[2], out_pics[0], 0);
cout<<"::N1"<<endl;
classify(weight, pics[5], pic[5], out_pics[0], 1);
classify(weight, pics[5], pic[5], out_pics[0], 2);
cout<<"::C1"<<endl;
classify(weight, pics[6], pic[6], out_pics[0], 3);
classify(weight, pics[6], pic[6], out_pics[0], 4);
cout<<"::C2"<<endl;
classify(weight, pics[7], pic[7], out_pics[0], 5);
classify(weight, pics[7], pic[7], out_pics[0], 6);


    return 0;
}
