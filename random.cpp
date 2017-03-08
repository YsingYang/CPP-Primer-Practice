#include <iostream>
#include <vector>
#include <numeric>
#include<limits>
#include<random>

using namespace std;
double leartCurve(double mu1, double sigma1, double mu2, double sigma2) {
    default_random_engine randomNum;
    default_random_engine randomNum2;
    normal_distribution<double> n(mu1,sigma1);
    normal_distribution<double> n2(mu2,sigma2);
    int count =0;
    for(int i=0;i<1000000;++i){
       double x = n(randomNum);
        double y = n2(randomNum2);
        if(pow(pow(x,2)+pow(y,2)-1,2)-pow(x,2)*pow(y,2)<=0)
            ++count;
    }
    return count/1000000.0;
}


int main(){
    double res;
    double _mu1;
    cin >> _mu1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    double _sigma1;
    cin >> _sigma1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    double _mu2;
    cin >> _mu2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    double _sigma2;
    cin >> _sigma2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    res = leartCurve(_mu1, _sigma1, _mu2, _sigma2);
    cout << res << endl;

    return 0;

}

