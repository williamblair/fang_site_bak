/* William Blair
 * CS 548 
 * 10/18/17 
 * Assignment 3 - Sphere Class Modified */

#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include "Surface.hpp"

class Sphere : public Surface
{
public:
    /* constructors */
    Sphere();
    Sphere(glm::vec3 center, double radius);
    ~Sphere();
    
    /* getter functions */
    glm::vec3 getCenter(void);
    double getRadius(void);
    int getMaterialIndex(void);
    
    /* setter functions */
    void setMaterialIndex(int matIndex);
    
    /* reads data through the given string */
    void read(std::string data);
    
    /* returns the center and radius as a string */
    std::string toString(void);

private:
    glm::vec3 center;
    double radius;

    int matIndex; // current Material Index
};

#endif // SPHERE_H_INCLUDED
