#include "include/Values.h"
using namespace std;

double input_values[11];

int main(int argv, char ** argc)
{
  char * input_file ;
  if (argv < 2) input_file = 
  Values *val_1=nullptr;
  
  val_1->assign(input_values);
  val_1=new Values(input_values[0],input_values[1],input_values[2],input_values[3],input_values[4],input_values[5],input_values[6],input_values[7],input_values[8],input_values[9],input_values[10]);

  val_1->print_values();
  calculated_values[0]=val_1->principal();
  calculated_values[1]=val_1->amortization();
  val_1->p=calculated_values[0];
  val_1->amtz=calculated_values[1];
  calculated_values[2]=val_1->principal_remaining();
  calculated_values[3]=val_1->total_revenue();	
  val_1->tr=calculated_values[3];
  calculated_values[4]=val_1->base_cost();
  val_1->bc=calculated_values[4];
  calculated_values[5]=val_1->calculated_cost();
  val_1->cc=calculated_values[5];
  calculated_values[6]=val_1->total_cost();						  
  val_1->tc=calculated_values[6];
  calculated_values[7]=val_1->net_profit();
  calculated_values[8]=val_1->selling_price();

  val_1->write_out();

  return 0;
}
