/*kohonen(self organised) maps - delevoped by SerhyPyton*/
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <chrono>
#include <iomanip>
#include <random>
#include <algorithm>
#include <sstream>

using namespace cv;
using namespace std;

int read_img(char *name, int n, vector<Mat>& pic)
{
    Mat img;
    Mat image;
    img = imread(name);
    cvtColor( img, image, CV_RGB2GRAY);
    pic[n]=image;
    return 0;
}

void gen_rand(vector<vector<Mat>>& w){
    std::random_device rd;

    std::mt19937 e2(rd());

    std::normal_distribution<> dist(90, 20);
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            for(int r=0;r<128;r++){
                for(int k=0;k<128;k++){
                    w[j][i].at<uchar>(r,k)=(int)dist(e2);
                }
            }
        }
    }
}

int diff(const Mat& w, const Mat& pic){
    int d=0;
    for (int j=0;j<128;j++){
        for (int i=0;i<128;i++){
            d += abs((int)pic.at<uchar>(j,i)-(int)w.at<uchar>(j,i));
        }
    }
    return d;
}

double dist(int j1,int i1,int j2,int i2){
    if (max(abs(j1-j2),abs(i1-i2))==0) return 0.5;
    if (max(abs(j1-j2),abs(i1-i2))==1) return 0.25;
    return 0.;
}

void learn(vector<vector<Mat>>& w, Mat& pic, int y, int x, int tt){
    for(int k=0;k<3;k++){
    for(int t=0;t<3;t++){
    for (int j=0;j<128;j++){
        for(int i=0;i<128;i++){
            w[k][t].at<uchar>(j,i)+=((int)pic.at<uchar>(j,i)-(int)w[k][t].at<uchar>(j,i))*dist(k, t, y, x)*(1./tt);
        }
    }
    }
    }
}

int main(int argc, char* argv[])
{
    //init
    vector<Mat> pic(7);
    read_img("images/c.png", 0, pic);
    read_img("images/g.png", 1, pic);
    read_img("images/m.png", 2, pic);
    read_img("images/n.png", 3, pic);
    read_img("images/s.png", 4, pic);
    read_img("images/n1.png", 5, pic);
    read_img("images/c1.png", 6, pic);
    vector<vector<Mat>> w(3, vector<Mat>(3));
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            pic[0].copyTo(w[i][j]);
        }
    }
    gen_rand(w);

    //imwrite("intial_rand.png",w[1][1]);
    //find the nearest
    for(int tt=0;tt<50;tt++){
    for (int k=0;k<5;k++){
    int d=100000000;
    int y=0;
    int x=0;
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            if ( diff(w[j][i],pic[k]) < d ){
                d=diff(w[j][i],pic[k]);
                y=j;
                x=i;
            }
        }
    }
   // cout<<" nearest to pic[0] ["<<y<<" , "<<x<<"]"<<endl;

    learn(w,pic[k],y,x, tt);

    }
    }


    int d=100000000;
    int y=0;
    int x=0;
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            if ( diff(w[j][i],pic[5]) < d ){
                d=diff(w[j][i],pic[5]);
                y=j;
                x=i;
            }
        }
    }
cout<<"n1 is related to ["<<y<<" , "<<x<<"]"<<endl;
        namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
  //  imwrite("related_weight_1.png",w[y][x] );
    imshow( "Display window", w[y][x] );                   // Show our image inside it.
    waitKey(0);


    d=100000000;
    y=0;
    x=0;
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            if ( diff(w[j][i],pic[6]) < d ){
                d=diff(w[j][i],pic[6]);
                y=j;
                x=i;
            }
        }
    }
cout<<"c1 is related to ["<<y<<" , "<<x<<"]"<<endl;
        namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
  //  imwrite("related_weight_2.png",w[y][x] );
    imshow( "Display window", w[y][x] );                   // Show our image inside it.
    waitKey(0);



    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
        namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", w[j][i] );                   // Show our image inside it.
    stringstream ss;
    ss<<"weight_"<<j<<"_"<<i<<".png";
    imwrite(ss.str(),w[y][x] );
    waitKey(0);
        }
    }
      //      cout<<(int)pic[2].at<uchar>(1,2);

    return 0;
}
