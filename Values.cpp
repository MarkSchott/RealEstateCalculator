#ifndef VALUES_CPP
#define VALUES_CPP
#include "../include/Values.h"
using namespace std;


Values::Values(double a,double b,double c,double d,double e,double f,int g,double h,double i,double j,int k)
{
  initial_property_value=a;
  down_payment=b;
  monthly_maintenance=c;
  farming_revenue=d;
  rental_revenue=e;
  improvements=f;
  months_owned=g;
  property_tax_rate=h;
  annual_mortgage_rate=i;
  target_growth_rate=j;
  mortgage_length=k;
}
                                                                                                                                                                                 
  void Values::assign(double *a)                                                                                                                                                            
{                                                                                                                                                                                  
  ifstream infile;              
  infile.open("input.txt");                                                                                                                              
  int i=0;                                                                                                                                                         
  double f;                                                                                                                                                                        
  while (!(infile.eof()))                                                                                                                                                          
    {                                                                                                                                                                                    infile >> f;                                                                                                                                                                      a[i]=f;                                                                                                                                                           
       i++;    
}                                                                                                                                                                          
infile.close();                                                                                                                                                                  
}                                                                                                                                                                                 

void Values::print_values()
{
  cout << initial_property_value <<endl;
  cout << down_payment<<endl;
  cout << monthly_maintenance<<endl;
  cout << farming_revenue<<endl;
  cout << rental_revenue<<endl;
  cout << improvements<<endl;
  cout << months_owned<<endl;
  cout << property_tax_rate<<endl;
  cout << annual_mortgage_rate<<endl;
  cout << target_growth_rate<<endl;
  cout << mortgage_length<<endl;
}

double Values::principal()
{//a is initial property value, b is down payment                                                                                                                                  
  return (initial_property_value-down_payment);
}
double Values::principal_remaining()
	      //a is principal, b is annual_mortgage_rate, c is months_owned, and d is amortization                                                                                              
{
  double z=p*pow((1+annual_mortgage_rate/12),months_owned)-amtz*(pow((1+annual_mortgage_rate/12),months_owned)-1)/(annual_mortgage_rate/12);
  return z;
}
double Values::total_revenue ()
	      //a is months_owned, b is farming revenue, c is rental revenue, d is initial property value, e is target growth rate                                                               
{
double z;
z=months_owned*(farming_revenue+rental_revenue)+initial_property_value*pow((1+target_growth_rate),months_owned/12);
return z;
}
double Values::amortization()
	      //a is initial_property value, b is annual_mortgage rate, c is down payment, d is mortgage_length                                                                                  
{
  double z;
  z=(initial_property_value-down_payment)*annual_mortgage_rate/12*pow(1+annual_mortgage_rate/12,mortgage_length)/(pow(1+annual_mortgage_rate/12,mortgage_length)-1);
  return z;
}
double Values::base_cost()
	      //a=months owned, b=monthly_maintenance, c= initial_property value, d=improvements                                                                                                 
{
  double z;
  z=months_owned*(monthly_maintenance)+initial_property_value+improvements;
  return z;
}
double Values::calculated_cost()
	      //a=initial property value, b=months owned, c=property tax rate, d=target growth rate                                                                                              
	      //calculated cost is the amount of property tax paid per month taking into account the property growth rate                                                                        
{
  double z=0;
  double calc[months_owned];
  int x=months_owned;
  while (!(x<=0))
    {
      calc[x-1]=property_tax_rate/12*(initial_property_value*pow((1+target_growth_rate/12),x));
      x=x-1;
    }
  for (int j=0;j<months_owned;j++)
    {
      z+=calc[j];
}
return z;
}

double Values::selling_price()
	      //a=initial price,b=months owned,c=target growth rate                                                                                                                              
{
  double z;
  z=initial_property_value*pow((1+target_growth_rate),months_owned/12);
  cout <<"This is z and months owned over 12 " <<z<<" " <<months_owned/12<<endl;
  cout <<"This is months_owned " <<months_owned<<endl;
  return z;
}
double Values::total_cost()
{
  return (bc+cc);
}
double Values::net_profit()
{
  return (tr-tc);
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

#endif
