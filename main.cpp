#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <functional> 
#include <random>
using namespace std;
const int MAKS=1000;
class obiekt_funkcyjny{
int n;
public:
	obiekt_funkcyjny(int arg_n):n(arg_n){}
	double operator()(){
		return MAKS/n+rand()%(MAKS/(n*n))-MAKS/(n*n*2);
	}
};
double myaccumulator (double x, double y) {
	if(x+y== 0) return 0;
	double temp=x-y;
	return pow(temp,2)/(x+y);
}
double round( double fValue )
{
	if(fValue<1.0 && fValue>0.0) floor( fValue);
    return fValue < 0.0 ? ceil( fValue - 0.5 ): floor( fValue + 0.5 );
}
int main(void){
	vector<double> v(10,0); 
	vector<double> v2(10,0);// inicjalizacja bufora: 10 liczb o wartoœci 0
	srand (time(NULL));
	string test;
	/// zadanie przed æw
    random_device rd; 
    mt19937 engine(rd()); 
	normal_distribution<> normal(4.5, 3.0); 
	for (int i=0,j=0;i<MAKS || j<MAKS;){
		double temp=round(normal(engine));
		if(temp<10.0 && temp>=0.0 && i<MAKS){
			v[temp]++; 
			i++;
		}
		temp=round(normal(engine));
		if(temp<10.0 && temp>=0.0 && j<MAKS){
			v2[temp]++; 
			j++;
		}
	}
	///// 5pkt/*
	/*
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
	/*
	for (int i=0;i<MAKS; i++){
		v[rand() % MAKS/100]++; // wylosuj komórkê bufora i zwiêksz jej wartoœæ o 1
		v2[rand() % MAKS/100]++;
	}*/
	for(vector<double>::iterator i=v.begin(),j=v2.begin();i!=v.end() && j!=v2.end();i++,j++)
		cout<<*i<<' '<<*j<<endl;
	cout<<">>"<<std::inner_product(v.begin(),v.end(),v2.begin(),0.0,plus<double>(),myaccumulator)<<"<<"<<'\n';
	return 0;
}