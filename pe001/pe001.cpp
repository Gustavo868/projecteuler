#include <iostream>
#include<chrono>

using namespace std;

long int soma_pa(long int a1, long int n) {
    return a1 * (n + 1) * n / 2;
}

long int quant_multiplo(long int num, long int mult){
    return static_cast<long int>(num/mult);
}

int main(){
    auto start = chrono::steady_clock::now();
    long int n = 1000000;
    
    long int quant15 = quant_multiplo(n,15);
    long int quant5 = quant_multiplo(n,5);
    long int quant3 = quant_multiplo(n,3);
    
    long int soma_mult15 = soma_pa(15,quant15);
    long int soma_mult5 = soma_pa(5,quant5);
    long int soma_mult3 = soma_pa(3,quant3);
    
    long int total = soma_mult3 + soma_mult5 - soma_mult15;
    
    cout << total << "\n";
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    
    return 0;
}
