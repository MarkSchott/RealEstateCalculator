#ifndef VALUES_CPP
#define VALUES_CPP
#include "include/Values.h"
using namespace std;

/*
  Reading in key=value pairs from the user provided (or default) input file and complaining if there is no match which is designated explicited in the class interface 
*/

Values::Values(string input_file) { 
                     
  ifstream infile;              
  infile.open(input_file);
  string keyval;
  string key ;
  string value ;
  int delim_pos = 0 ;

  /*Read in values that were provided in the file*/
  while (!(infile.eof()))
    {
      infile >> keyval ;
      delim_pos = keyval.find('=', 0) ;
      key = keyval.substr(0, delim_pos) ;
      if ( params.find(key) == params.end() ) {
	cerr << key << " is not a valid key\n " ;
	continue ;
      }
      value = keyval.substr(delim_pos + 1, string::npos) ;
      delim_pos = 0 ;
      params[key] = stod(value) ;
    }

  infile.close();

  /*
    OPTIONAL FUTURE SUPPORT:
    Now read in the values that were provided manually on the command line which will overwrite the 
    ones provided in the file
  */
}

void Values::print_values()
{
  /* Iterate through the unordered_map and print each key and value */
  for (auto& x: params) {
    cout << x.first << ": " << x.second << endl ;
  }
}

double Values::principal()
{
  return (params[IPV] - params[DP]);
}

double Values::principal_remaining()

{
  double P_remaining;
  P_remaining = \
    params[IPV] * pow((1 + params[AMR] / 12), params[MO])- amortization() \
    * (pow(( 1 + params[AMR] / 12), params[MO]) - 1)/(params[AMR] / 12);
  return P_remaining;
}

double Values::total_revenue ()
{
  double z;
  z = params[MO] * (params[FR] + params[RR]) + params[IPV] \
    * pow((1 + params[TGR]), params[MO] / 12);
  return z;
}

double Values::amortization()
{
  double z;
  z = (params[IPV] - params[DP]) * (params[AMR] / 12)	\
    * pow(1 + params[AMR] / 12, params[ML]) \
    /(pow(1 + params[AMR] / 12, params[ML]) - 1);
  return z;
}

double Values::base_cost()
{
  double z;
  z = params[MO] * (params[MM]) + params[IPV] + params[IMPROVS];
  return z;
}

double Values::calculated_cost()
/*
  calculated cost is the amount of property tax paid per month taking into 
  account the property growth rate                                              */                          
{
  double z = 0;
  double calc[(int)params[MO]];
  int x = (int)params[MO];
  while (!(x<=0))
    {
      calc[x-1] = params[PTR]/12 * (params[IPV] * pow((1 + params[TGR]/12),x));
      x=x-1;
    }
  for (int j=0;j<params[MO];j++)
    {
      z += calc[j];
}
return z;
}

double Values::selling_price()
{
  double z;
  z = params[IPV] * pow((1 + params[TGR]), params[MO]/12);
  return z;
}
										
										
double Values::total_cost()
{
  return (base_cost() + calculated_cost());
}

double Values::net_profit()
{
  return (total_revenue() - total_cost());
}
										
/*
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
*/
#endif
