/* William Blair
 * CS 548 
 * 09/12/17 
 * Assignment 2 - Light Class */

#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED

#include <glm/glm.hpp>
#include <iostream>
#include <sstream>
#include <string>

class Light
{
public:
    /* Constructors */
    Light(void);
    Light(glm::vec3 pos);
    Light(glm::vec3 pos, glm::vec3 color);
    
    /* Deconstructor */
    ~Light(void);
    
    /* Getter methods */
    glm::vec3 getPos(void);
    glm::vec3 getColor(void);
    
    /* reads in a string with position
     * and optional color data */
    void read(std::string data);
    
    /* returns the position/color
     * data as a string */
    std::string toString(void);

private:
    glm::vec3 pos;
    glm::vec3 color;

};

#endif // LIGHT_H_INCLUDED
