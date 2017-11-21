#include <iostream>

using namespace std;

typedef double (*FUNC)(double);

double line(double x);
double square(double x);
double cube(double x);
double integrate(FUNC f, double a, double b);

int main(){
	
	
	cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line,1,5) << endl;
	cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square,1,5) << endl;
	cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube,1,5) << endl;
	
}

double line(double x){
	return x;

}

double square(double x){
	return x*x;

}

double cube(double x){
	return x*x*x;	

}

double integrate(FUNC f, double a, double b){
	double dx = 0.000001;
	double sum = 0.0;	
	for (int i = 0; i < (int)(1000000*(b-a)); i++){
		double doub_i = (double) i;
		sum += f(a+(doub_i*dx)) * dx;
	}	
	return sum;
}
