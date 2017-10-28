/* William Blair
 * CS 548 
 * 09/12/17 
 * Assignment 2 - Sphere Class */

#include "Sphere.hpp"

/* Sets center and radius
 * data from a string with the format:
 * s x y z r */
void Sphere::read(std::string data)
{
    std::istringstream s(data); // string stream to parse data
    
    /* Test if the line starts with 's' */
    char testChar = (char)0;
    s >> testChar;
    if(testChar != 's'){
        std::cerr << "Sphere::read: Invalid String: '" <<
            data << "' doesn't start with 's'\n";
        return;
    }
    
    /* read x,y,z, and radius and test for error */
    if(!(s >> center.x >> center.y >> center.z >> radius)){
        std::cerr << "Sphere::read: Invalid String: '" <<
            data << "' failed to read data\n";
        return;
    }
    
}

/* returns the center and radius as a string 
 * in the following format:
 * s x y z radius */
std::string Sphere::toString(void)
{
    std::ostringstream s; // output string stream
    
    s << "s " << center.x << " " << center.y 
        << " " << center.z << " " << radius;
    
    return s.str();
}

/***************************************/
/**           CONSTRUCTORS            **/
/***************************************/
Sphere::Sphere(void)
: center(0.0f,0.0f,0.0f),
  radius(1.0f)
{
}

Sphere::Sphere(glm::vec3 center, double radius)
{
    this->center = center;
    this->radius = radius;
}

Sphere::~Sphere()
{
}

/***************************************/
/**             GETTERS               **/
/***************************************/
glm::vec3 Sphere::getCenter(void)
{
    return center;
}

double Sphere::getRadius(void)
{
    return radius;
}
