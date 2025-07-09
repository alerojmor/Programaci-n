#include <iostream>

using namespace std;
int step=0;

int main()
{
cout<<"Ingrese por favor el numero de escalones: ";
cin>>step;
cout<<endl;
    for(int i=1;i<=step;i++){

        for(int j=1;j<=i;j++){
        cout <<"#";
        }
        cout <<endl;
        }
    return 0;
}
