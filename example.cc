#include <utility>
#include <string>
#include <cassert>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <vector>
#include "example.h"

using namespace std;

void check_case() {
  
  int n;
  judge_in >> n;

  cout<<n<<endl;
  double xsum = 0, ysum = 0;
  for(int i=0;i<n;++i){
    double x,y;
    judge_in>>x>>y;
    cout<<x<<" "<<y<<endl;
    xsum += x; ysum += y;
  }

  double xavg, yavg;
  if(!(author_out >> xavg))
    wrong_answer("Expected real number");
  if(!(author_out >> yavg))
    wrong_answer("Expected real number");

  double actual_xavg, actual_yavg;
  judge_ans >> actual_xavg >> actual_yavg;

  double distance = sqrt(pow(actual_xavg - xavg, 2) + pow(actual_yavg - yavg, 2));

  if(distance > 1e-3)
    wrong_answer("Answer too far apart");

}

int main(int argc, char **argv) {
  init_io(argc, argv);

  check_case();

  /* Check for trailing output. */
  string trash;
  if (author_out >> trash) {
      wrong_answer("Trailing output\n");
  }

  /* Yay! */
  accept();
}
