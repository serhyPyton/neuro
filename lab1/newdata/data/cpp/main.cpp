
#include <string>
#include <vector>
#include <sstream> //istringstream
#include <iostream> // cout
#include <fstream> // ifstream

using namespace std;

/**
 * Reads csv file into table, exported as a vector of vector of doubles.
 * @param inputFileName input file name (full path).
 * @return data as vector of vector of doubles.
 */
vector<vector<double>> parse2DCsvFile(string inputFileName) {

    vector<vector<double> > data;
    ifstream inputFile(inputFileName);
    int l = 0;

    while (inputFile) {
        l++;
        string s;
        if (!getline(inputFile, s)) break;
        if (s[0] != '#') {
            istringstream ss(s);
            vector<double> record;

            while (ss) {
                string line;
                if (!getline(ss, line, ';'))
                    break;
                try {
                    record.push_back(stof(line));
                }
                catch (const std::invalid_argument e) {
                    cout << "NaN found in file " << inputFileName << " line " << l
                         << endl;
                    e.what();
                }
            }

            data.push_back(record);
        }
    }

    if (!inputFile.eof()) {
        cerr << "Could not read file " << inputFileName << "\n";
        __throw_invalid_argument("File not found.");
    }

    return data;
}
float math(float w[3], float x[3]){
    float res =0;
    for (int i=0; i<=2; i++){
        res=res+w[i]*x[i];
    }
    return res;
}
void print(float a[3], float b[3]){
    for (int i=0; i<=2; i++){
        cout<< "frst arr :"<< a[i]<< "sec arr :"<<b[i]<<endl;
    }
}

int main()
{
    vector<vector<double>> data;
    data = parse2DCsvFile("data01.csv");
    float arr[100][3];
    int a=0;
    int b=0;
    for (auto l : data) {
        for (auto x : l){
       //     cout << x << " ";
            arr[a][b]=x;
           // cout << " ar a:"<<a<<" b:"<<b<<" "<< arr[a][b]<< " ;;";
            b++;
        }
      //  cout << endl;
        a++;
        b=0;
    }
    float arr1[75][3];
    for (int a=0; a<=74; a++){
        for (int b=0; b<=2; b++){
            if (b==2) arr1[a][b]=1;
            else arr1[a][b]=arr[a][b];
        }
    }

/* for (int a=0; a<=74; a++){
        for (int b=0; b<=2; b++){
            cout<< arr1[a][b]<<" ";
        }
        cout<< endl;
    } */

float w[3]= {0.5,0.5,0.5};
int acc = 0;
for(int f=0; f<=10; f++){
     for (int a=0; a<=74; a++){
         if (math(w,arr1[a])>0) acc=1;
         else acc=0;
   // cout << "acc "<< acc<< endl; //acc- our desicion
        //update
        for (int i=0; i<=2; i++){
            w[i]=w[i]+(arr[a][2]-acc)*0.1*arr1[a][i];
     //   cout<< "w[i]="<<w[i]<<" d="<< acc<< " y="<<arr[a][2]<<" x[k]="<<arr1[a][i]<<endl;
        }
    }
    int c =0;
     for (int a=0; a<=74; a++){
        if (math(w,arr1[a])>0.5 && arr[a][2] ==1) c++;
        if (math(w,arr1[a])<0.5 && arr[a][2] ==0) c++;
    }
    cout << "c="<<c <<" "<< w[0]<<" "<<w[1]<<" "<<w[2]<<endl;
}
    float arr2[25][3];
    for (int a=0; a<=24; a++){
        for (int b=0; b<=2; b++){
            if (b==2) arr2[a][b]=1;
            else arr2[a][b]=arr[75+a][b];
        }
    }
    int c=0;
     for (int a=0; a<=24; a++){
        if (math(w,arr2[a])>0.5 && arr[a+75][2] ==1) c++;
      //  print(arr2[a], arr[a+75]);
        if (math(w,arr2[a])<0.5 && arr[a+75][2] ==0) c++;
    }
    cout << "C="<<c <<" "<< w[0]<<" "<<w[1]<<" "<<w[2]<<endl;

    return 0;
}