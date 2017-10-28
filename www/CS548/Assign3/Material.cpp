/* William Blair
 * CS 548
 * 10/18/17
 * Assignment 3
 * Material.cpp - implementation file for Material Class */

#include "Material.hpp"

/* Sets Material data
 * from a string with the format:
 * f r g b Kd Ks Shine T index_of_refraction */
void Material::read(std::string data)
{
    std::istringstream s(data); // string stream to parse data
    
    /* Test if the line starts with 's' */
    char testChar = (char)0;
    s >> testChar;
    if(testChar != 'f'){
        std::cerr << "Material::read: Invalid String: '" <<
            data << "' doesn't start with 'f'\n";
        return;
    }
    
    /* read color r,g,b, and test for error */
    if(!(s >> diffuse.r >> diffuse.g >> diffuse.b)){
        std::cerr << "Material::read: Invalid String: '" <<
            data << "' failed to read diffuse color data\n";
        return;
    }
    
    /* Read Coefficients and test for error */
    if(!(s >> Kd >> Ks >> shine)){
        std::cerr << "Material::read: Invalid String: '" <<
            data << "' failed to read coefficients\n";
        return;
    }
    
    /* Read remaining Transmittance and refraction index
     * and test for error */
    if(!(s >> transmittance >> refracIndex)){
        std::cerr << "Material::read: Invalid String: '" <<
            data << "' failed to read transmittance or \
                    refraction index\n";
        return;
    }    
}

/* returns the Material data as a string
 * in the following format:
 * f r g b Kd Ks Shine T index_of_refraction */
std::string Material::toString(void)
{
    std::ostringstream s; // output string stream
    
    s << "f " << diffuse.r << " " << diffuse.g 
      << " "  << diffuse.b << " " << Kd
      << " "  << Ks << " " << shine << " "
      << transmittance << " " << refracIndex;
    
    return s.str();
}

/***************************************/
/**           CONSTRUCTORS            **/
/***************************************/

Material::Material(void)
: diffuse(1,1,1),
  Kd(1.0),
  Ks(0.0),
  shine(1.0),
  transmittance(0.0),
  refracIndex(1.0)
{}

/***************************************/
/**             GETTERS               **/
/***************************************/
glm::vec3 Material::getColor(void)
{
    return diffuse;
}
float Material::getKd(void)
{
    return Kd;
}
float Material::getKs(void)
{
    return Ks;
}
float Material::getShine(void)
{
    return shine;
}
float Material::getTransmittance(void)
{
    return transmittance;
}
float Material::getIndexRefraction(void)
{
    return refracIndex;
}