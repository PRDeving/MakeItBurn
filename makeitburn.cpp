#include <iostream>
#include <ctime>
#include <thread>
#include <vector>
#include <random>
#include <string>

using namespace std;

vector<thread> threads;
void memtest();
void cputest();

int menu(){
    int option;
    cout << "Choose an option" << endl
         << " 1) MEMORY" << endl
         << " 2) CPU" << endl
         << " 3) EXIT" << endl;
    cin >> option;

    switch(option){
        case 1:
            memtest();
            break;
        case 2:
            cputest();
            break;
        default:
            return 0;
            break;
    }
    return 0;
}

void burncpu(unsigned int instance){
    for(unsigned int num = 1; num <= 100000000; num++){
        unsigned int i = 2;
        while(i <= num){
            if(num % i == 0)
                break;
            i++;
        }
    }
}

void memtest(){
    while(1){
        int* p=(int*)malloc(4);
        if(!p)break;
    }
    cout << "memtest" << endl;
}

void cputest(){
    cout << "1.000.000 instances launched to calculate prime numbers" << endl;
    cout << "Working ..." << endl;
    for(unsigned int x = 0; x < 1000000; x++){
        threads.push_back(thread(burncpu, x));
    }
    for(unsigned int x = 0; x < 1000000; x++){
        threads[x].join();
    }
}

int main(){
    srand(time(0));
    menu();
    return 0;
}
