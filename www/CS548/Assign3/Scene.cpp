/* William Blair
 * CS 548
 * 10/18/17
 * Assignment 3
 * Scene.cpp - implementation for Scene Class */
 
#include "Scene.hpp"

/* Returns the scene data in the following format:
 * b red green blue
 * (Camera NFF format)
 * (light NFF format)
 * (material NFF format)
 * (surface NFF format) */
std::string Scene::toString(void)
{
    std::ostringstream s; // output string stream
    
    /* add the background color */
    s << "b " << bgColor.r << " " << bgColor.g
      << " " << bgColor.b << "\n";
    
    /* add the camera info */
    if(camera) s << camera->toString() + "\n";
    
    /* add each light info */
    for(Light *light : lights)
    {
        if(light) s << light->toString() + "\n";
    }
    
    /* add each material info */
    for(Material *m : materials)
    {
        if(m) s << m->toString() + "\n";
    }
    
    /* add each surface info */
    for(Surface *surface : surfaces)
    {
        if(surface) s << surface->toString() + "\n";
    }
    
    return s.str();
}

/* Loads a given NFF file into each
 * scene component */
bool Scene::loadNFF(std::string filename)
{
    /* Load the file */
    std::ifstream f(filename);
    if(!f.is_open()) {
        std::cerr << "Scene.cpp: Failed to open '" << filename <<
            "'\n";
        return false;
    }
    
    /* Destroy any existing objects */
    cleanup();
    
    /* keep track of the material index 
     * for the sphere */
    int currentMatIndex = -1;
    
    /* Loop through the file */
    while(!f.eof())
    {
        std::string line; // the current line in the file
        std::getline(f, line);
        
        std::istringstream s(line); // to parse the line
        
        std::string firstWord;
        s >> firstWord;
        
        /* If the line defines a light */
        if(firstWord.compare("l") == 0)
        {
            /* Create a new light, read
             * the line, and add it to the
             * vector of lights */
            Light *l = new Light;
            l->read(line);
            lights.push_back(l);
        }
        /* If the line defines a sphere */
        else if(firstWord.compare("s") == 0)
        {
            /* Create a new sphere, read
             * the line, set its material
             * index, and add it to the
             * vector of surfaces */
            Sphere *sp = new Sphere;
            sp->read(line);
            sp->setMaterialIndex(currentMatIndex);
            surfaces.push_back((Surface*)sp);
        }
        /* If the line defines a material */
        else if(firstWord.compare("f") == 0)
        {
            /* Create a new material, read
             * the line, and add it to the
             * vector of materials */
            Material *m = new Material;
            m->read(line);
            materials.push_back(m);
            
            /* we have a new material;
             * increment the material index */
            currentMatIndex++;
        }
        /* If the line defines a background color */
        else if(firstWord.compare("b") == 0)
        {
            /* keep reading the string stream 
             * to get the color */
            if(!(s >> bgColor.r >> bgColor.g >> bgColor.b)){
                std::cerr << "Scene.cpp: Failed to read \
                            bg color from file\n";
            }
        }
        /* If the line defines a camera */
        else if(firstWord.compare("v") == 0)
        {
            this->camera = new Camera;
            
            /* get the current line, we'll
             * need to add more */
            std::string c_data = line;
            
            /* get the next six lines 
             * for the camera */
            for(int i=0; i<6; i++)
            {
                std::string next_line;
                std::getline(f, next_line);
                
                c_data += next_line + "\n";
            }
            
            /* assign it to our camera */
            camera->read(c_data);
        }
        /* Unhandled lines will go here */
        /*else
        {
            std::cout << "Scene.cpp: Unhandled NFF \
                        Line: '" << line <<"'\n";
        }*/
    }
    
    /* close the file */
    f.close();
        
    /* get viewport size */
    glm::ivec2 vsize = camera->getViewportSize();
    this->bw = vsize[0];
    this->bh = vsize[1];
        
    /* Initialize the image buffer */
    imageBuffer = new float[3 * bw * bh];
        
    return true;
}
 
/***************************************/
/**           CONSTRUCTORS            **/
/***************************************/

Scene::Scene(void)
: camera(NULL),
  imageBuffer(NULL),
  bw(0),
  bh(0),
  bgColor(0,0,0)
{}

/***************************************/
/**             GETTERS               **/
/***************************************/

int Scene::getLightCnt(void)
{
    return lights.size();
}
int Scene::getSurfaceCnt(void)
{
    return surfaces.size();
}
int Scene::getMaterialCnt(void)
{
    return materials.size();
}
int Scene::getBufferWidth(void)
{
    return bw;
}
int Scene::getBufferHeight(void)
{
    return bh;
}
float *Scene::getImageBuffer(void)
{
    return imageBuffer;
}
Camera *Scene::getCamera(void)
{
    return camera;
}

/***************************************/
/**          DECONSTRUCTORS           **/
/***************************************/
void Scene::cleanup(void)
{
    unsigned int i=0;
    
    /* Free all lights and clear list */
    for(i=0; i<lights.size(); i++)
    {
        if(lights.at(i)) delete lights.at(i);
    }
    lights.clear();
    
    /* Free all surfaces and clear list */
    for(i=0; i<surfaces.size(); i++)
    {
        if(surfaces.at(i)) delete surfaces.at(i);
    }
    surfaces.clear();
    
    /* Free all materials and clear list */
    for(i=0; i<materials.size(); i++)
    {
        if(materials.at(i)) delete materials.at(i);
    }
    materials.clear();
    
    /* Free image buffer */
    if(imageBuffer) {
        delete imageBuffer;
        imageBuffer = NULL;
    }
    
    /* Free camera */
    if(camera){
        delete camera;
        camera = NULL;
    }
}

Scene::~Scene(void)
{
    cleanup();
}
