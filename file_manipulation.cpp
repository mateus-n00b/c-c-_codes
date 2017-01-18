#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outfile;
	ifstream infile;
	char path[30],data[100];
	int opt = 0;
	cout << "Choose an option: \n[1] READ\n[2] WRITE\n[3] EXIT\n >> " ;
	cin >> opt;
	switch(opt){
	case 1:		
			cout << "Insert the file to be read: ";
			cin >> path;
			try
			{
				infile.open(path);	
				cout << "Content of the file: " << path << endl;
				infile >> data;
				cout << data << endl;
				infile.close();
			}
			catch (const char *msg)
			{
				cerr << "[-] Error to read!!!" << endl;
			}	
		return 0;
	case 2: 
		 	cout << "Insert the file to be writed: ";
			cin >> path;
			try
			{
				outfile.open(path);													
				cout << "Insert the text: " ;			
				cin >> data;
				outfile << data << endl;
				outfile.close();
				cout << "[+] All Done!!!\n" ; 
			}
			catch (const char *msg)
			{
				cerr << "[-] Error to write!!!\n" << endl;
			}
		return 0;
	case 3:
			cout << "[+] Bye";
			return 0;
	default: 
			cout << "[-] Choose an option (1,2 or 3)" << endl;
			return 0;
	}	
}
