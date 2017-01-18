#include <iostream>
#include <iomanip>
using namespace std;
using std::setw;

int main()
{
	int n [ 10 ];
	for (int x = 0 ; x <= 9; x++){
		n[ x ] = x+100;	
	}
	cout << "Elemento " << setw(13) << "Valor" << endl;
	for (int i = 0; i <= 9 ; i++) {
		cout << setw(7) << i << setw(13) << n[i]<< endl;
		
	}
return 0;
}
