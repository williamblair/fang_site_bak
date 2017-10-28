/* William Blair
 * CS 548 
 * 09/12/17 
 * Assignment 2 - Light Class */

#include "Light.hpp"

/* Sets position and (optionally) color
 * data from a string with the format:
 * l x y z
 *   or
 * l x y z r g b */
void Light::read(std::string data)
{
    std::istringstream s(data); // string stream to parse data
    
    /* Test if the line starts with 'l' */
    char testChar = (char)0;
    s >> testChar;
    if(testChar != 'l'){
        std::cerr << "Light::read: Invalid String: '" <<
            data << "' doesn't start with 'l'\n";
        return;
    }
    
    /* read x,y, and z and test for error */
    if(!(s >> pos.x >> pos.y >> pos.z)){
        std::cerr << "Light::read: Invalid String: '" <<
            data << "' failed to read position data\n";
        return;
    }
    
    /* end if at the end of the stringstream 
     * but set the color to default white first */
    s >> std::ws; // get rid of extra whitespace
    if(s.eof()){
        color.r = color.g = color.b = 1.0f;
        return;
    }
    
    /* otherwise read color data and error check */
    if(!(s >> color.r >> color.g >> color.b)){
        std::cerr << "Light::read: Invalid String: '" <<
            data << "' failed to read color data\n";
        return;
    }
    
}

/* return position and color data
 * as a string in the format: 
 * l x y z r g b */
std::string Light::toString(void)
{
    std::ostringstream s; // output string stream
    
    s << "l " << pos.x << " " << pos.y 
        << " " << pos.z << " " << color.r
        << " " << color.g << " "  
        << color.b;
    
    return s.str();
}

/***************************************/
/**           CONSTRUCTORS            **/
/***************************************/
Light::Light(void)
: pos(0.0f,0.0f,0.0f),
  color(1.0f,1.0f,1.0f)
{
}

Light::Light(glm::vec3 pos)
: color(1.0f,1.0f,1.0f)
{
    this->pos = pos;
}

Light::Light(glm::vec3 pos, glm::vec3 color)
{
    this->pos = pos;
    this->color = color;
}

Light::~Light(void)
{
}

/***************************************/
/**             GETTERS               **/
/***************************************/
glm::vec3 Light::getPos(void)
{
    return pos;
}

glm::vec3 Light::getColor(void)
{
    return color;
}
