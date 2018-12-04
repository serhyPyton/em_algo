#include <vector>
#include <math.h>

using namespace std;


void learn(vector<vector<double>>& alfa, vector<double>& appr, vector<double>& mean, vector<double>& disp, vector<double>& pic, int n, int t){
while (t>0){
   //alfa

        for(int w=0;w<n;w++){

            alfa[w][0]=1.0/ (1.0 + ( (appr[1]*disp[0])/(appr[0]*disp[1]) )* exp( -(1.0/2.0) * ( pow((pic[w]-mean[1]),2)/pow(disp[1],2) - pow((pic[w]-mean[0]),2)/pow(disp[0],2) )));
            alfa[w][1]=1.0/ (1.0 + ( (appr[0]*disp[1])/(appr[1]*disp[0]) )* exp( -(1.0/2.0) * ( pow((pic[w]-mean[0]),2)/pow(disp[0],2) - pow((pic[w]-mean[1]),2)/pow(disp[1],2) )));

    }
    //appr

            double alfa0=0;
            double alfa1=0;
            for(int w=0;w<n;w++){
                alfa0+=alfa[w][0];
                alfa1+=alfa[w][1];
            }
            appr[0]=alfa0/(double)n;
            appr[1]=alfa1/(double)n;

    //mean

             alfa0=0;
             alfa1=0;
            double alfa00=0;
            double alfa11=0;
            for(int w=0;w<n;w++){
                alfa0+=alfa[w][0]*pic[w];
                alfa1+=alfa[w][1]*pic[w];
                alfa00+=alfa[w][0];
                alfa11+=alfa[w][1];
            }
            mean[0]=alfa0/alfa00;
            mean[1]=alfa1/alfa11;

    //disp

             alfa0=0;
             alfa1=0;
             alfa00=0;
             alfa11=0;
            for(int w=0;w<n;w++){
                alfa0+=alfa[w][0]*pow((pic[w]-mean[0]),2);
                alfa1+=alfa[w][1]*pow((pic[w]-mean[1]),2);
                alfa00+=alfa[w][0];
                alfa11+=alfa[w][1];
            }
            disp[0]=sqrt(alfa0/alfa00);
            disp[1]=sqrt(alfa1/alfa11);

t--;
}
}
