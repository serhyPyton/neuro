#include <iostream>
#include "read_csv.cpp"
#include "k_means.cpp"

using namespace std;

int main(){

    vector<vector<double>> data = parse2DCsvFile("data01.csv");
    float arr[100][3];
    int a=0;
    int b=0;
    for (auto l : data) { //WHYYYYYY!!!!
        for (auto x : l){
            cout << x << " ";
            arr[a][b]=x;
            cout << arr[a][b]<< " ;;";
            b++;
        }
        cout << endl;
        a++;
        b=0;
    }
    for(int i=0;i<100;i++){
        for (int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


}
