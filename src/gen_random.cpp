
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

void gen_rand_normal(vector<double>& pic, double mean, double disp, int n){
            std::random_device rd;

    std::mt19937 e2(rd());

    std::normal_distribution<> dist(mean, disp);

    for(int w=0;w<n; w++){ //get gray set of images
                pic[w]= dist(e2);
              //  std::cout << pic[w]<<' ';
        }
}

void gen_rand_uniform(vector<double>& pic, double mean, double disp, int n){

 	std::default_random_engine generator;
 	std::uniform_int_distribution<int> distribution(mean, disp);

	for (int i=0; i<n; ++i) {
    	pic[i] = distribution(generator);
	}
}
