#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <functional> 
using namespace std;

const int MAKS=1000;
class obiekt_funkcyjny{
int n;
public:
	obiekt_funkcyjny(int arg_n):n(arg_n){}
	double operator()(){
		//srand (time(NULL)); // siema nie rób tak, bo to pewnie sie wykonuje co 10000 razy w ci¹gu sekundy, wiec wszystkie wniki beda takie same
		return MAKS/n+rand()%(MAKS/(n*n))-MAKS/(n*n*2);
	}
};
double myaccumulator (double x, double y) {
	if(x+y== 0) return 0;
	double temp=x-y;
	return pow(temp,2)/(x+y);
}
int main(void){
	double init=0;
	
	vector<double> v(10,0); 
	vector<double> v2(10,0);// inicjalizacja bufora: 10 liczb o wartoœci 0
	srand (time(NULL));
	
	///// 5pkt
	generate(v.begin(),v.end()-1,obiekt_funkcyjny(v.size()));
	double temp;
	for(vector<double>::iterator i=v.begin();i!=v.end();){
		temp+=*i++;
		if(i==v.end()-1) *i=MAKS-temp;
	}
	temp=0;
	generate(v2.begin(),v2.end()-1,obiekt_funkcyjny(v2.size()));
	for(vector<double>::iterator i=v2.begin();i!=v2.end();){
		temp+=*i++;
		if(i==v2.end()-1) *i=MAKS-temp;
	}/// koniec 5 pkt, odkomentowac to co jest nizej, jezeli chesz miec na 3, a zakomentowac za 5 pkt
	
	/*for (int i=0;i<1000; i++){
		v[rand() % 10]++; // wylosuj komórkê bufora i zwiêksz jej wartoœæ o 1
		v2[rand() % 10]++;
	}*/

	for(vector<double>::iterator i=v.begin(),j=v2.begin();i!=v.end() && j!=v2.end();i++,j++)
		cout<<*i<<' '<<*j<<endl;
	
	cout<<">>"<<std::inner_product(v.begin(),v.end(),v2.begin(),init,plus<double>(),myaccumulator)<<"<<"<<'\n';
	return 0;
}