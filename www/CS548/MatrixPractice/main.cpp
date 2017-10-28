#include <iostream>
#include <string>
#include "glm/glm.hpp"					// NOTE: Need to compile, hence the quotes
#include "glm/gtx/string_cast.hpp"
#include "glm/gtc/matrix_transform.hpp"

using namespace std;

void printRM(string name, glm::mat3 &M)
{
  cout << name << ":" << endl;
  
  int row,col;
  for(row=0; row<3; row++)
  {
    for(col=0; col<3; col++)
    {
      /* column major matrices */
      cout << M[col][row] << ", ";
    }
    cout << endl;
  }
}

int main(int argc, char *argv[])
{
  cout << "BEGIN MATRIX EXERCISE" << endl;
  
  /* column major order: col1=[1,2,3], col2=[4,5,6], col3=[7,8,9] */
  glm::mat3 M = glm::mat3(1,2,3,4,5,6,7,8,9);
  
  /* default constructor - identity matrix */
  glm::mat3 T;
  glm::mat3 I(1.0);
  
  /* generate from 3 vectors */
  glm::vec3 U = glm::normalize(glm::vec3(1,1,0));
  glm::vec3 V = glm::normalize(glm::vec3(-1,1,0));
  glm::vec3 W = glm::normalize(glm::cross(U, V));
  glm::mat3 B = glm::mat3(U, V, W);
  
  /* transpose */
  glm::mat3 Mt = glm::transpose(M);
  
  /* add */
  glm::mat3 C = M + B;
  
  /* multiply */
  glm::mat3 Eight = 8.0f*I;
  
  /* Matrix multiply */
  glm::mat3 A = glm::mat3(
    1,2,3,
    0, -1, 1,
    3, 2, 1
  );
  glm::mat3 D = glm::mat3(
    5,4,1,
    6, 3, 1,
    5, 2, 2
  );
  glm::mat3 E = A*D;
  
  /* Matrix-Vec multiply */
  glm::mat3 F = glm::mat3(5, 0, 0, 0, 2, 0, 0, 0, -1);
  glm::vec3 g = glm::vec3(7, 16, 9);
  glm::vec3 h = F*g;
  
  printRM("M", M);
  printRM("T", T);
  printRM("I", I);
  printRM("[U,V,W]", B);
  
  printRM("Mt", Mt);
  printRM("C", C);
  printRM("Eight", Eight);
  
  printRM("E", E);
  cout << glm::to_string(h) << endl;

  return 0;
}