/* William Blair
 * CS 548 
 * 09/12/17 
 * Assignment 2 - Sphere Class */

#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <sstream>
#include <string>

class Sphere
{
public:
    /* constructors */
    Sphere();
    Sphere(glm::vec3 center, double radius);
    ~Sphere();
    
    /* getter functions */
    glm::vec3 getCenter(void);
    double getRadius(void);
    
    /* reads data through the given string */
    void read(std::string data);
    
    /* returns the center and radius as a string */
    std::string toString(void);

private:
    glm::vec3 center;
    double radius;

};

#endif // SPHERE_H_INCLUDED
