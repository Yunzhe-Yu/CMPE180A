//Yunzhe Yu 015287714
//Professor:Ron Mak
//Date:8/27/2020 16:34
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int    MAX_ITERATIONS = 20;
const double TOLERANCE      = 1.0e-17;

/**
 * Compute the factorial of an integer value.
 * @param n the value.
 * @return n! as a double.
 */
double factorial(int n);

/**
 * Compute the arctangent of a double value.
 * @param x the value.
 * @return an estimate of arctan(x).
 */
double arctangent(double x);

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_0();

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_1();

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_2();

/**
 * Compute an estimate of pi using a formula by the Chudnovsky brothers.
 * @return an estimate of pi.
 */
void Chudnovsky();

/**
 * Compute an estimate of pi using an arctangent formula by Machin.
 * @return an estimate of pi.
 */
void Machin();

int main()
{
    cout << fixed << setprecision(16);

    cout << endl;
    cout << "Ramanujan pi recipe #0:" << endl << endl;
    Ramanujan_0();

    cout << endl;
    cout << "Ramanujan pi recipe #1:" << endl << endl;
    Ramanujan_1();

    cout << endl;
    cout << "Ramanujan pi recipe #2:" << endl << endl;
    Ramanujan_2();

    cout << endl;
    cout << "Chudnovsky pi recipe:" << endl << endl;
    cout << "  Iteration  Estimate" << endl;
    Chudnovsky();

    cout << endl;
    cout << "Machin pi recipe:" << endl << endl;
    Machin();



    return 0;
}

double factorial(int n)
{
    double nf = 1;
    for (int i = 2; i <= n; i++) nf *= i;
    return nf;
}

void Ramanujan_0()
{
    cout << " Estimate:  ";
    double factor0 = 12 / sqrt((double)190);
    double factor1 = (2*sqrt((double)2)+sqrt((double)10))*(3+sqrt((double)10));
    double factor2 = log((double)factor1);
    //use the algorithm that on the pdf.
    cout<<factor0*factor2<<endl;
    /***** Completed by 8/25/2020 23:52*****/
}

void Ramanujan_1()
{
    cout << "  Iteration  Estimate" << endl;

    double one_over_pi;
    double factor0 = sqrt((double) 8)/(99*99);
    double sum  = 0.0;
    double prev = 0.0;
    double diff = 0.0;

    int n = 0;

    do
    {
        double factor1 = factorial(4*n)/pow((pow(4.0, n)*factorial(n)), 4);
        double factor2 = ((double) 1103 + 26390*n)/pow((double) 99, 4*n);

        sum += factor1*factor2;

        one_over_pi = factor0*sum;
        cout << setw(11) << n+1 << "  " << 1.0/one_over_pi << endl;

        diff = abs(prev - one_over_pi);
        prev = one_over_pi;
        n++;
    } while ((diff > TOLERANCE) && (n <= MAX_ITERATIONS));
}

void Ramanujan_2()
{
    cout << "  Iteration  Estimate" << endl;
	double pi;
	double sum = 0.0;
	double diff = 0.0;
	double pre = 0.0;
	int n = 0;
	do {
		double factor1 = (pow((-1.0),n)*factorial(4*n))/(pow((pow(4.0, n)*factorial(n)), 4));//first part
		double factor2 = ((double) 1123 + 21460*n)/pow((double) 882, 2*n); //second part
		//Here are some codes that I sepreate these algorithm step by step and try to check the answer.
		/*double factor3 = pow(-1,n);
		double factor4 = factorial(4*n);
		double factor5 = factor3*factor4;
		double factor6 = pow(4.0,n);
		double factor7 = factorial(n);
		double factor8 = factor7 * factor6;
		double factor9 = pow(factor8,4);
		double factor10 = factor5/factor9;
*/

		sum+= factor1 * factor2;
		pi = sum / 882;
		cout<<setw(11)<<n+1<<" "<<4.0/pi<<endl;

		diff = abs(pre - pi);
		pre = pi;
		n++;

	}while ((diff > TOLERANCE) && (n <= MAX_ITERATIONS));//same as #1
    /***** Completed at 8/26/2020 22:43. *****/
}

void Chudnovsky()
{


    double pi;
    double sum  = 0.0;
    double pre = 0.0;
    double diff = 0.0;

    int n = 0;

    do
    {
    	double factor0 = pow(-1,n);
    	double factor1 = factorial(6*n);
    	double part1 = factor0 * factor1;
    	double factor2 = factorial(3*n);
    	double factor3 = pow(factorial(n),3);
    	double part2 = factor2*factor3;
    	double firstpart = part1 / part2;
    	double factor4 = pow(pow(640320,3), n+0.5);
    	double factor5 = ((double)13591409 + 545140134*n);
    	double secpart = factor5 / factor4;
    	double whole = firstpart*secpart;//I sepreate these algorithm step by step avoid to some mistakes.
    	pi = 12*whole;
    	sum = sum + pi;
    	cout<<setw(11)<<n+1<<" "<<1.0/sum<<endl;
    	diff = abs(pre-pi);
    	pre = pi;
    	n=n+1;
    } while ((diff > TOLERANCE) && (n <= MAX_ITERATIONS)&& (n<3) );//Total 3 times!
    /***** Completed at 8/26/2020 22:48 *****/
}

double arctangent(double x)
{
    double arctan = x;
    double arctan_increase = pow(x,2);
	double sum = 0.0;
	int n = 1;
	int i = 0;
	do
	{
		double factor = arctan / n;
		if(pow(-1,i)>0){//if (-1)^n > 0, then s=s+f, if (-1)^n < 0, then s = s-f, else failed.
			sum = sum + factor;
		}else if(pow(-1,i)<0){
			sum = sum - factor;
		}else{
			cout<<"failed!"<<endl;
		}
		i = i + 1;

		arctan = arctan * arctan_increase;//1:x, 2:x^3, 3:x^5,etc
		n = n+2;
	}while(arctan/n > pow(0.1,17));

    /***** Completed at 8/26/2020 23:24*****/

    return sum;
}

void Machin()
{
    double pi_over_4 = 4*arctangent(0.2) - arctangent(1.0/239.0);
    cout << "  Estimate:  " << 4*pi_over_4 << endl;
}
