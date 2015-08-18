#include <iostream>
#include <ctime>
#include <thread>
#include <vector>
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
    unsigned int num = 1;
    while(true){
        unsigned int i = 2;
        while(i <= num){
            if(num % i == 0)
                break;
            i++;
        }
        num++;
    }
}

void memtest(){
    cout << "Testing memory, your machine will probably freeze" << endl;
    while(true){
        int* p=(int*)malloc(4);
        if(!p)break;
    }
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
    menu();
    return 0;
}
