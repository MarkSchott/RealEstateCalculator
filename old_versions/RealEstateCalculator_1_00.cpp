#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
double input_values[12];
double calculated_values[11];
double principal, principal_remaining,total_revenue,amortization,net_profit,net_profit_per_month,total_cost,calculate_cost,base_cost,monthly_mortgage_rate,months_owned;
// input values
/* 0=initial_property_value
   1=down payment
   2=monthly_maintenance
   3=farming_revenue
   4=rental_revenue
   5=improvements
   6=selling_price
   7=months_owned
   8=property_tax_rate
   9=annual_mortgage_rate
   10=target_growth_rate
   11=years_owned
*/
//calculated values
/*
0=principal
1=principal remaining
2=total_revenue
3=amortization
4=net_profit
5=net_profit_per_month
6=total_cost
7=calculate_cost
8=base_cost
9=monthly_mortgage_rate
10=months_owned
*/

//function definitions
//Plan is to separate RealEstateCalculator into multiple functions. I also want to read in all the values from a text file rather than prompting for them each time. Once read in, they need to be assigned to an array and then operated upon. It can be either be two arrays, one of numbers and the other of chars, or one matrix. Once all the values are calculated, they must be outputed in a clear format. I also want to split it up as much as possible because I want to turn this into a gui. 
void assign()
{
  ifstream infile;
  infile.open("input.txt");
  int i=0;
  double f;
  while (!(infile.eof))
    { 
      infile >> f;
      values[i]=f;
      i++
	}
  infile.close();
}

double principal(double input_0, double input_1)
{
  return input_0-input_1;
}
double principal_remaining(double calc_0,double input_7,double input_9,double calc_3))
{
  double z=calc_0*pow((1+input_9/12),input_7)-calc_3*(pow((1+input_9/12),input_7)-1)/(input_9/12);
  return z;
}
double total_revenue (double input_7,double input_3,double input_4,double input_0, double input_10)
{
  double zz;
  zz=input_7*(input_3+input_4)+input_0*pow((1+input_10),input_7/12);
  return zz;
}
double amortization()
{
  int zzz;
  amortization=(initial_property_value-down_payment)*monthly_mortgage_rate*pow(1+monthly_mortgage_rate,n)/(pow(1+monthly_mortgage_rate,n)-1);







int main()
{ 
  cout << "Please enter the total property price: ";
  cin  >> initial_property_value;
  cout << "Please enter your down payment, the more the better!: ";
  cin  >> down_payment;
  principal=initial_property_value-down_payment;
  cout << "How much to fix it up?: ";
  cin  >> improvements;
  cout << "How much farming revenue per month?: " ;
  cin  >> farming_revenue;
  cout << "How much renting revenue per month?: ";
  cin  >> rental_revenue;
  cout << "Estimate the monthly maintenance cost?: ";
  cin  >> monthly_maintenance;
  cout << "Please enter the annual mortgage interest rate in decimal form: ";
  cin  >> annual_mortgage_rate;
  monthly_mortgage_rate=annual_mortgage_rate/12;
  cout << "Please enter the property tax rate: ";
  cin  >> property_tax_rate;
  cout << "How many months is the mortgage?: ";
  cin  >> n;
  cout << "How many months do you plan on owning it?: ";
  cin  >> months_owned;
  years_owned=months_owned/12;
  cout << "Please enter the target growth rate per year?: ";
  cin  >> target_growth_rate;
//Calculation of the interesting stuff
  selling_price=initial_property_value*pow((1+target_growth_rate),years_owned);
  total_revenue=months_owned*(farming_revenue+rental_revenue)+initial_property_value*pow((1+target_growth_rate),years_owned);

  if (!(principal==0)) 
    {
      amortization=(initial_property_value-down_payment)*monthly_mortgage_rate*pow(1+monthly_mortgage_rate,n)/(pow(1+monthly_mortgage_rate,n)-1);
      //calculate principal remaining
      if (!(months_owned>240))
	{
      principal_remaining=principal*pow((1+monthly_mortgage_rate),months_owned)-amortization*(pow((1+monthly_mortgage_rate),months_owned)-1)/monthly_mortgage_rate;
	}
      else principal_remaining=0;      
total_cost=months_owned*(monthly_maintenance+amortization)+improvements+(property_tax_rate*initial_property_value)*pow((1+target_growth_rate),years_owned)+principal_remaining+down_payment;
      cout<<"This is the principal remaining " <<principal_remaining<<endl;
}
  else 
{
  amortization=0; 
  while (!(years_owned<=0))
    {;
      base_cost=months_owned*(monthly_maintenance)+initial_property_value+improvements;
      calculate_cost=property_tax_rate*(initial_property_value*pow((1+target_growth_rate),years_owned)); 
      total_cost+=calculate_cost;
      cout << "These are total cost and years owned " << total_cost << "  " <<years_owned <<endl;
      years_owned=years_owned-1;    
}}
  total_cost=total_cost+base_cost;
  net_profit=total_revenue-total_cost;
  cout << "This is your amortization payment: " << amortization << endl;
  cout << "This is what the house sold for: " << selling_price <<endl;
  cout << "This is your net profit: " <<net_profit<<endl;

  /*
  //Opening a file and writing to it
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
