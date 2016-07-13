#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
double input_values[11];
double calculated_values[9];
// input values
/* 0=initial_property_value
   1=down payment
   2=monthly_maintenance
   3=farming_revenue
   4=rental_revenue
   5=improvements
   6=months_owned
   7=property_tax_rate
   8=annual_mortgage_rate
   9=target_growth_rate
   10=mortgage_length
*/
//calculated values
/*
0=principal
1=amortization
2=principal remaining
3=total_revenue
4=base_cost
5=calculate_cost
6=total_cost
7=net_profit
8=selling_price
*/

//function definitions
//I am going to further improve this program by putting all of the functions into a class. Then I will create an object for each set of values I want to calculate.
class Values {
public:
  void assign();
  void write_out();

  double principal(double,double);
  double principal_remaining(double,double,double,double);
  double total_revenue(double,double,double,double,double);
  double amortization(double,double,double,double);
  double base_cost(double,double,double,double);
  double calculated_cost(double,double,double,double);
  double selling_price(double,double,double);
  double total_cost(double,double);
  double net_profit(double,double);
};
  void Values::assign()
{
  ifstream infile;
  infile.open("input.txt");
  int i=0;
  double f;
  while (!(infile.eof()))
    { 
      infile >> f;
      input_values[i]=f;
      i++;
	}
  infile.close();
}

double Values::principal(double a, double b)
{//a is initial property value, b is down payment
  return a-b;
}
double Values::principal_remaining(double a,double b,double c,double d)
//a is principal, b is annual_mortgage_rate, c is months_owned, and d is amortization
{
  double z=a*pow((1+b/12),c)-d*(pow((1+b/12),c)-1)/(b/12);
  return z;
}
double Values::total_revenue (double a,double b,double c,double d, double e)
//a is months_owned, b is farming revenue, c is rental revenue, d is initial property value, e is target growth rate
{
  double z;
  z=a*(b+c)+d*pow((1+e),a/12);
  return z;
}
double Values::amortization(double a, double b, double c, double d) 
//a is initial_property value, b is annual_mortgage rate, c is down payment, d is mortgage_length
{
  double z;
  z=(a-c)*b/12*pow(1+b/12,d)/(pow(1+b/12,d)-1);
  return z;
}
double Values::base_cost(double a,double b, double c,double d)
//a=months owned, b=monthly_maintenance, c= initial_property value, d=improvements
{
  double z;
  z=a*(b)+c+d;
  return z;
}
double Values::calculated_cost(double a,double b, double c, double d)
//a=initial property value, b=months owned, c=property tax rate, d=target growth rate
//calculated cost is the amount of property tax paid per month taking into account the property growth rate
{
  double z=0;
  int months_owned=b;
  double calc[months_owned];
  while (!(months_owned<=0))
    {
      calc[months_owned-1]=c/12*(a*pow((1+d/12),months_owned)); 
      months_owned=months_owned-1;   
    }
  for (int j=0;j<input_values[6]+1;j++)  
    {
z+=calc[j];
}
  return z;
}

double Values::selling_price(double a, double b, double c)
//a=initial price,b=months owned,c=target growth rate
{
  double z;
  z=a*pow((1+c),b/12);
  return z;
}
double Values::total_cost(double a,double b)
{
  return a+b;
}
double Values::net_profit(double a,double b)
{
  return a-b;
}
void Values::write_out()
{
				     //Writing all the output values to a file
				     ofstream myfile;
				     myfile.open("Calculated_Values.txt");
				     for (int h=0;h<9;h++)
				       {
					 myfile <<calculated_values[h] <<endl;
				       }
				     myfile.close();
}
int main()
{ 
  Values *val_1=nullptr;

  val_1->assign();

  calculated_values[0]=val_1->principal(input_values[0],input_values[1]);
  calculated_values[1]=val_1->amortization(input_values[0],input_values[8],input_values[1],input_values[10]);
  calculated_values[2]=val_1->principal_remaining(calculated_values[0],input_values[8],input_values[6],calculated_values[1]);
  calculated_values[3]=val_1->total_revenue(input_values[6],input_values[3],input_values[4],input_values[0],input_values[9]);		    
  calculated_values[4]=val_1->base_cost(input_values[6],input_values[2],input_values[0],input_values[5]);
  calculated_values[5]=val_1->calculated_cost(input_values[0],input_values[6],input_values[7],input_values[9]);				     
  calculated_values[6]=val_1->total_cost(calculated_values[4],calculated_values[5]);						  
  calculated_values[7]=val_1->net_profit(calculated_values[3],calculated_values[6]);
  calculated_values[8]=val_1->selling_price(input_values[0],input_values[6],input_values[9]);

  val_1->write_out();

  return 0;
}
