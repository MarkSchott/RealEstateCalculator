#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
double input_values[11]={0,0,0,0,0,0,0,0,0,0,0};
double calculated_values[9]={0,0,0,0,0,0,0,0,0};
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
//Plan is to separate RealEstateCalculator into multiple functions. I also want to read in all the values from a text file rather than prompting for them each time. Once read in, they need to be assigned to an array and then operated upon. It can be either be two arrays, one of numbers and the other of chars, or one matrix. Once all the values are calculated, they must be outputed in a clear format. I also want to split it up as much as possible because I want to turn this into a gui. 
void assign()
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

double principal(double a, double b)
{//a is initial property value, b is down payment
  return a-b;
}
double principal_remaining(double aa_1,double bb_1,double cc_1,double dd_1)
//aa is principal, bb is annual_mortgage_rate, cc is months_owned, and dd is amortization
{
  double z=aa_1*pow((1+bb_1/12),cc_1)-dd_1*(pow((1+bb_1/12),cc_1)-1)/(bb_1/12);
  return z;
}
double total_revenue (double aa,double bb,double cc,double dd, double ee)
//aa is months_owned, bb is farming revenue, cc is rental revenue, dd is initial property value, ee is target growth rate
{
  double zz;
  zz=aa*(bb+cc)+dd*pow((1+ee),aa/12);
  return zz;
}
double amortization(double aaa, double bbb, double ccc, double ddd) 
//aaa is initial_property value, bbb is annual_mortgage rate, ccc is down payment, ddd is mortgage_length
{
  double zzz;
  zzz=(aaa-ccc)*bbb/12*pow(1+bbb/12,ddd)/(pow(1+bbb/12,ddd)-1);
  return zzz;
}
double base_cost(double aaaa,double bbbb, double cccc,double dddd)
//aaaa=months owned, bbbb=monthly_maintenance, cccc= initial_property value, dddd=improvements
{
  double zzzz;
  zzzz=aaaa*(bbbb)+cccc+dddd;
  return zzzz;
}
double calculated_cost(double aaaaa,double bbbbb, double ccccc, double ddddd)
//aaaaa=initial property value, bbbbb=months owned, ccccc=property tax rate, ddddd=target growth rate
//calculated cost is the amount of property tax paid per month taking into account the property growth rate
{
  double zzzzz=0;
  int months_owned=bbbbb;
  double calc[months_owned];
  while (!(months_owned<=0))
    {
      calc[months_owned-1]=ccccc/12*(aaaaa*pow((1+ddddd/12),months_owned)); 
      months_owned=months_owned-1;   
    }
  for (int j=0;j<input_values[6]+1;j++)  
    {
zzzzz+=calc[j];


}
  
  return zzzzz;
}

double selling_price(double aaaaaa, double bbbbbb, double cccccc)
//aaaaaa=initial price,bbbbbb=months owned,cccccc=target growth rate
{
  double zzzzzz;
  zzzzzz=aaaaaa*pow((1+cccccc),bbbbbb/12);
  return zzzzzz;
}

int main()
{ 
  assign();

  calculated_values[0]=principal(input_values[0],input_values[1]);
  calculated_values[1]=amortization(input_values[0],input_values[8],input_values[1],input_values[10]);
  calculated_values[2]=principal_remaining(calculated_values[0],input_values[8],input_values[6],calculated_values[1]);
  calculated_values[3]=total_revenue(input_values[6],input_values[3],input_values[4],input_values[0],input_values[9]);		    
  calculated_values[4]=base_cost(input_values[6],input_values[2],input_values[0],input_values[5]);
  calculated_values[5]=calculated_cost(input_values[0],input_values[6],input_values[7],input_values[9]);				     calculated_values[6]=calculated_values[4]+calculated_values[5];						  
  calculated_values[7]=calculated_values[3]-calculated_values[6];
  calculated_values[8]=selling_price(input_values[0],input_values[6],input_values[9]);

				     //Writing all the output values to a file
				     ofstream myfile;
				     myfile.open("Calculated_Values.txt");
				     for (int h=0;h<9;h++)
				       {
					 myfile <<calculated_values[h] <<endl;
				       }
				     myfile.close();

  //Opening a file and writing to it
				     /*
  ofstream myfile;
  myfile.open("Mortgagevalues.txt");
  x=0;
  annual_mortage_rate=0;
  monthly_mortgage_rate=0;
  while (x< 80)
    {
      annual_mortage_rate=x*.001;
      monthly_mortgage_rate=annual_mortage_rate/12;
      if (!(monthly_mortgage_rate==0)) amortization=(initial_property_value-down_payment)*monthly_mortgage_rate*pow(1+monthly_mortgage_rate,n)/(pow(1+monthly_mortgage_rate,n)-1);
      else amortization=0;
      myfile << amortization << "\t";
      myfile << annual_mortage_rate<< "\t";
      myfile << monthly_mortgage_rate <<endl;
      x++;
    }
  myfile.close();  
				     */
  return 0;
}
