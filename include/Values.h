#ifndef VALUES_H
#define VALUES_H
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

//double calculated_values[9];

class Values {

  string IPV = "initial_property_value" ;
  string DP = "down_payment" ;
  string MM = "monthly_maintenance" ;
  string FR = "farming_revenue" ;
  string RR = "rental_revenue" ;
  string IMPROVS = "improvements" ;
  string MO = "months_owned";
  string PTR = "property_tax_rate" ;
  string AMR = "annual_mortgage_rate" ;
  string TGR = "target_growth_rate" ;
  string ML = "mortgage_length" ;

  unordered_map<string, double> params {
      { IPV, 0 } ,
      { DP, 0 } ,
      { MM, 0} ,
      { FR, 0 } ,
      { RR, 0 } ,
      { IMPROVS, 0 } ,
      { MO, 0 } ,
      { PTR, 0 } ,
      { AMR, 0 } ,
      { TGR, 0 } ,
      { ML, 0 }
    } ;

 public:

  Values(string) ;

  // void write_out();
  void print_values();
  double principal();
  double principal_remaining();
  double total_revenue();
  double amortization();
  double base_cost();
  double calculated_cost();
  double selling_price();
  double total_cost();
  double net_profit();


  double p;
  double amtz;
  double tr;
  double bc;
  double cc;
  double tc;
};

#endif
