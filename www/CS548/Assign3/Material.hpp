/* William Blair
 * CS 548
 * 10/18/17
 * Assignment 3
 * Material.hpp - header for Material Class */

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <sstream>
#include <string>

#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

class Material
{

public:
    /* Constructor */
    Material();
    
    /* reads data through the given string */
    void read(std::string data);
    
    /* returns the Material data as a string */
    std::string toString(void);
    
    /* Getters */
    glm::vec3 getColor(void);
    float     getKd(void);
    float     getKs(void);
    float     getShine(void);
    float     getTransmittance(void);
    float     getIndexRefraction(void);

private:
    glm::vec3 diffuse; // diffuse color
    float     Kd;  // diffuse coefficient
    float     Ks;  // specular coefficient
    float     shine; // shininess
    float     transmittance;
    float     refracIndex; // index of refraction
};

#endif