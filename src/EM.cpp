
#include <iostream>
#include <vector>
#include "learn.cpp"
#include "gen_random.cpp"

using namespace std;

int main()
{
int iter = 100;  //amount of iterations

int n1=100;         //amount of first distribution elements
int n2=200;         //second

double mean1=30;
double disp1=3;
double mean2=20;
double disp2=3;

        vector<double> mean(2);
        vector<double> disp(2);
        vector<double> appr(2);
        vector<double> pic(n1+n2);
        vector<vector<double>> alfa(n1+n2, vector<double>(2));

gen_rand(pic, mean1, disp1, n1, mean2, disp2, n2);  //returns pic - random values
                                                    //from given distributions

            mean[0]=pic[0];     //initial states
            mean[1]=pic[40];
            disp[0]=1;
            disp[1]=10;
            appr[0]=0.6;
            appr[1]=0.4;

learn(alfa, appr, mean, disp, pic, n1+n2, iter);     //last paramter - iterations


cout << "mean for 0 ";
        cout << mean[0]<<" "<<endl;
cout << "disp for 0 ";
        cout << disp[0]<<" "<<endl;
cout << "mean for 1 ";
        cout << mean[1]<<" "<<endl;
cout << "disp for 1 ";
        cout << disp[1]<<" "<<endl;
cout << "appr for 0 ";
        cout << appr[0]<<" "<<endl;
cout << "appr for 1 ";
        cout << appr[1]<<" "<<endl;
        return 0;
}
