#include <iostream>

using namespace std;


void collatz(int n){
cout<<n;
        while(n!=1){
        if(n%2==0){
                    n=n/2;
        }else{
                n=(3*n)+1;
        }
cout<<","<<n;
}
}

int main(){
int numero=0;
cout<<"por favor ingrese un numero: ";
cin>>numero;
cout<<endl;
cout<<"La secuencia de collatz del numero "<<numero<<" es: "<<endl;
collatz(numero);
cout<<endl;

return 0;
}
