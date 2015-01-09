#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <functional> 
using namespace std;
double myaccumulator (double x, double y) {
	if(x+y== 0) return 0;
	double temp=x-y;
	return pow(temp,2)/(x+y);}
double myproduct (double x, double y) {return x+y;}
int main(void){
	double init=0;
	
	vector<double> v(10,0); 
	vector<double> v2(10,0);// inicjalizacja bufora: 10 liczb o wartoœci 0
	srand (time(NULL));
	for (int i=0;i<1000; i++){
		v[rand() % 10]++; // wylosuj komórkê bufora i zwiêksz jej wartoœæ o 1
		v2[rand() % 10]++;
	}
	
	/*vector<double> v; //u¿ywane do tesotowania
	v.push_back(500.0);v.push_back(500.0);v.push_back(500.0);
	vector<double> v2;
	v2.push_back(400.0);v2.push_back(400.0);v2.push_back(400.0);*/
	
	for(vector<double>::iterator i=v.begin(),j=v2.begin();i!=v.end() && j!=v2.end();i++,j++)
		cout<<*i<<' '<<*j<<endl;
	
	cout<<">>"<<std::inner_product(v.begin(),v.end(),v2.begin(),init,myproduct,myaccumulator)<<"<<"<<'\n';
	return 0;
}