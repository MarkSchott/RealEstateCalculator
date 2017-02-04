#include "include/Values.h"
using namespace std;

int main(int argv, char ** argc)
  
{  
  string input_file ;
  
  /* 
     OPTIONAL FUTURE SUPPORT:
     Need to read in input file by a specific argument flag or make sure it ends in the right suffix
     if I really want to read it in from the command line with key value pairs
  */
  if (argv > 2) {
    cerr << "Improper usage!!! Only 2 arguments at most are allowed\n" ;
    cerr << "./main.x (optional file_name)\n" ;
    return -1 ;
  }
  
  else if (argv < 2) {
    cout << "Using default input file name \"input.txt\"\n" ;
    input_file = "input.txt" ;
  }

  else {
    input_file = argc[1] ;
  }
  
  Values *val_1=nullptr;

  val_1 = new Values(input_file) ;
  val_1 -> print_values();
  cout << "principal: " << val_1 -> principal() << endl ;
  cout << "principal remaining: " << val_1 -> principal_remaining() << endl ;
  cout << "amortization: " << val_1 -> amortization() << endl ;
  cout << "selling price: " << val_1 -> selling_price() << endl ;
  cout << "total cost: " << val_1 -> total_cost() << endl ;
  cout << "net_profit: " << val_1 -> net_profit() << endl ;  
  //  val_1->write_out();
  return 0;
}
