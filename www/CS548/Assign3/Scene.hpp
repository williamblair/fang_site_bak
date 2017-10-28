/* William Blair
 * CS 548
 * 10/18/17
 * Assignment 3
 * Scene.hpp - header for Scene Class */
 
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "Light.hpp"
#include "Material.hpp"
#include "Surface.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
 
#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
 
class Scene
{
public:
    
    /* Constructors */
    Scene(void);
    
    /* Deconstructors */
    void cleanup(void);
    virtual ~Scene(void);
    
    /* returns the NFF string
     * format of each part of the scene */
    std::string toString(void);
    
    /* Loads a given NFF file */
    bool loadNFF(std::string filename);
    
    /* Getters */
    int getLightCnt(void);    // # of lights
    int getSurfaceCnt(void);  // # of surfaces 
    int getMaterialCnt(void); // # of materials
    int getBufferWidth(void);
    int getBufferHeight(void);
    float *getImageBuffer(void);
    Camera *getCamera(void);
    
private:
    std::vector<Light*>     lights;
    std::vector<Material*>  materials;
    std::vector<Surface*>   surfaces;
    Camera                 *camera;
    float                  *imageBuffer;
    int                     bw; // buffer width
    int                     bh; // buffer height
    glm::vec3               bgColor; // background color
    
}; 
 
#endif
 