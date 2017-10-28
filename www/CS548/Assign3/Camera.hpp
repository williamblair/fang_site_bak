/* William Blair
 * CS 548 
 * 09/12/17 
 * Assignment 2 - Camera Class */

#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <glm/glm.hpp>
#include <iostream>
#include <sstream>
#include <string>

class Camera
{
public:
    /* Constructors */
    Camera(
        glm::vec3  eye, 
        glm::vec3  lookAt,
        glm::vec3  up, 
        float      angle,
        float      nearPlaneDist,
        glm::ivec2 viewportSize
    );
    Camera();
    ~Camera();
    
    /* Getter Functions */
    glm::vec3  getEye(void);
    glm::vec3  getLookAt(void);
    glm::vec3  getUp(void);
    float      getAngle(void);
    float      getNearPlaneDist(void);
    glm::ivec2 getViewportSize(void);
    
    /* Setter Functions */
    void setEye           (glm::vec3  eye           );
    void setLookAt        (glm::vec3  lookAt        );
    void setUp            (glm::vec3  up            ); 
    void setAngle         (float      angle         );
    void setNearPlaneDist (float      nearPlaneDist );
    void setViewportSize  (glm::ivec2 viewportSize  );
    
    /* reads the private variables from the
     * given string */
    void read(std::string data);
    
    /* returns the private data in string form */
    std::string toString(void);
    
private:
    glm::vec3 eye;       // camera position
    glm::vec3 lookAt;    // position to look at
    glm::vec3 up;        // direction up is in
    
    float      angle;
    float      nearPlaneDist;
    glm::ivec2 viewportSize;
    
    /* reads the next string from the
     * stringstream and reports if it isn't
     * equal to str */
    bool testRead(const std::string data,
        std::istringstream &s, const std::string str);

};

#endif // CAMERA_H_INCLUDED
