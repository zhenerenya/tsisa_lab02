#include <iostream>
#include <random>
#include <algorithm>
#include "math.h"
#include <map>
#include <iomanip>

double f (const double & x){
    return exp((-0.2)*x)*sin(x)+1;
}

double _x (double a, double b){
    return 1.*(b-a)*rand()/RAND_MAX+a;
}

double f_multi (const double & x){
    return f(x)*sin(5*x);
}


int main() {
    double A, B; //диапозон поиска
    A=9;
    B=12;
    srand(time(NULL));
    std::vector<double>P;
    std::vector<double>q;
    for (double i=0.9; i<1; i+=0.01){
        P.push_back(i);
    }
    for (double i=0.005; i<=0.1; i+=0.005){
        q.push_back(i);
    }


    for (const auto& i : P){
        std::cout<<"|"<<std::setw(4)<<"N"<<"|"<<std::setw(8)<<"P"<<"|"<<std::setw(8)<<"q"<<"|"<<
                 std::setw(10)<<"x_min"<<"|"<<std::setw(10)<<"f_min"<<"|"<<std::endl;
        double x;
        for (const auto& j : q){
            int N = ceil(log(1-i)/log(1-j));
            double f_min=f(A);
            double x_min=A;
            for (int k=0; k<N; k++){
                x=_x(A, B);
                if (f_min>=f(x)) {
                    f_min=f(x);
                    x_min=x;
                }
            }
            std::cout<<"|"<<std::setw(4)<<N<<"|"<<std::setw(8)<<i<<"|"<<std::setw(8)<<j<<"|"<<
                     std::setw(10)<<x_min<<"|"<<std::setw(10)<<f_min<<"|"<<std::endl;

        }

        std::cout<<std::setfill('=')<<std::setw(46)<<" ";
        std::cout<<std::endl<<std::setfill(' ');

    }

    std::cout<<"FOR MULTI F(X)*SIN(5X)"<<std::endl;

    for (const auto& i : P){
        std::cout<<"|"<<std::setw(5)<<"N"<<"|"<<std::setw(10)<<"P"<<"|"<<std::setw(10)<<"q"<<"|"<<
                 std::setw(10)<<"x_min"<<"|"<<std::setw(10)<<"f_min"<<"|"<<std::endl;
        double x;
        for (const auto& j : q){
            int N = ceil(log(1-i)/log(1-j));
            double f_min=f_multi(A);
            double x_min=A;
            for (int k=0; k<N; k++){
                x=_x(A, B);
                if (f_min>=f_multi(x)) {
                    f_min=f_multi(x);
                    x_min=x;
                }
            }
            std::cout<<"|"<<std::setw(5)<<N<<"|"<<std::setw(10)<<i<<"|"<<std::setw(10)<<j<<"|"<<
                     std::setw(10)<<x_min<<"|"<<std::setw(10)<<f_min<<"|"<<std::endl;

        }

        std::cout<<std::setfill('=')<<std::setw(52)<<" ";
        std::cout<<std::endl<<std::setfill(' ');

    }

}
