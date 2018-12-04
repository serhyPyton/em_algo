
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

void gen_rand(vector<double>& pic, double mean1, double disp1, int n1, double mean2, double disp2, int n2){
            std::random_device rd;

    std::mt19937 e2(rd());

    std::normal_distribution<> dist(mean1, disp1);
    std::normal_distribution<> dist1(mean2, disp2);

    for(int w=0;w<n1; w++){ //get gray set of images
                pic[w]= dist(e2);
              //  std::cout << pic[w]<<' ';
        }
    for (int w=n1;w<n1+n2; w++) {
                pic[w]= dist1(e2);
              //  std::cout << pic[w]<<' ';
        }
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
shuffle (pic.begin(), pic.end(), std::default_random_engine(seed));
}
