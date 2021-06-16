#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int ciagFib(int x){
	if(x <= 2){
		return 1;
	}
	return ciagFib(x-1) + ciagFib(x-2);
}

string decToOtherSystem(int x, int sys){
	string output;
	char z;
	if(!x) return "0";
	while(x>0){
		z = x%sys + '0';
		output = z + output;
		x /= sys;
	}
	return output;
}

int main(){
	
	cout << "67.3. " << endl;
	ofstream fraktal("wyniki.txt");
	int dlugosc40 = decToOtherSystem(ciagFib(40), 2).length();
	for(int a=1; a<=40; a++){
		int l = ciagFib(a);
		int iloscJedynek = 0;
		string inBin = decToOtherSystem(l, 2);
		for(int a=0; a<dlugosc40-inBin.length(); a++){
			cout << "0";
			fraktal << "0 ";
		}
		cout << inBin << endl;
		for(int q=0; q<inBin.length(); q++){
			fraktal << inBin[q] << " ";
			if(inBin[q] == '1'){
				iloscJedynek++;
			}
		}
		fraktal << endl;
		
		if(iloscJedynek == 6){
			vector<string> tmp;
			tmp.push_back(inBin);
		}
	}
	
