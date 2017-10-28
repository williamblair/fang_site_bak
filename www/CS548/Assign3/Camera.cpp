/* William Blair
 * CS 548 
 * 09/12/17 
 * Assignment 2 - Camera Class */

#include "Camera.hpp"

/* Helper function that reads the next string
 * from s and reports if it doesn't equal str
 * used by Camera::read */
bool Camera::testRead(const std::string data,
    std::istringstream &s, const std::string str)
{
    bool status = true;
    std::string dummyStr;
    s >> dummyStr;
    if(dummyStr != str){
        std::cerr << "Camera::read: Invalid String: '" <<
            data << "' Next group doesn't start with "<<
            str << "\n";
        status = false;
    }

    return status; 
}

/* reads the private variables from the
 * given string, in the following format:
 * v
 * from eye.x eye.y eye.z
 * at lookAt.x lookAt.y lookAt.z
 * up up.x up.y up.z
 * angle angle
 * hither nearPlaneDistance
 * resolution viewportSize.x viewportSize.y */
void Camera::read(std::string data)
{
    std::istringstream s(data); // string stream to parse data
    std::string        dummyStr; // holds the string at the beginning
                                 // of each line
    
    /* Test if the line starts with 'l' */
    char testChar = (char)0;
    s >> testChar;
    if(testChar != 'v'){
        std::cerr << "Camera::read: Invalid String: '" <<
            data << "' doesn't start with 'v'\n";
        return;
    }
    
    /* read eye x,y, and z and test for error */
    if(!testRead(data, s, "from")) return;
    if(!(s >> eye.x >> eye.y >> eye.z)){
        std::cerr << "Camera::read: Invalid String: '" <<
            data << "' failed to read eye data\n";
        return;
    }
    
    /* read at x,y, and z and test for error */
    if(!testRead(data, s, "at")) return; 
    if(!(s >> lookAt.x >> lookAt.y >> lookAt.z)){
        std::cerr << "Camera::read: Invalid String: '" <<
            data << "' failed to read lookAt data\n";
        return;
    }
    
    /* read up x,y, and z and test for error */
    if(!testRead(data, s, "up")) return; 
    if(!(s >> up.x >> up.y >> up.z)){
        std::cerr << "Camera::read: Invalid String: '" <<
            data << "' failed to read up data\n";
        return;
    }
    
    /* read angle and test for error */
    if(!testRead(data, s, "angle")) return; 
    if(!(s >> angle)){
        std::cerr << "Camera::read: Invalid String: '" <<
            data << "' failed to read angle data\n";
        return;
    }
    
    /* read hither and test for error */
    if(!testRead(data, s, "hither")) return; 
    if(!(s >> nearPlaneDist)){
        std::cerr << "Camera::read: Invalid String: '" <<
            data << "' failed to read hither/nearPlaneDistdata\n";
        return;
    }
    
    /* read resolution and test for error */
    if(!testRead(data, s, "resolution")) return; 
    if(!(s >> viewportSize.x >> viewportSize.y)){
        std::cerr << "Camera::read: Invalid String: '" <<
            data << "' failed to read viewPortSize data\n";
        return;
    }
}
    
/* returns a string of the data in the format:
 * v
 * from eye.x eye.y eye.z
 * at lookAt.x lookAt.y lookAt.z
 * up up.x up.y up.z
 * angle angle
 * hither nearPlaneDist
 * resolution viewPortSize.x viewPortSize.y */
std::string Camera::toString(void)
{
    std::ostringstream s; // output string stream
    
    s << "v\n"
      << "from " << eye.x << " " << eye.y << " " << eye.z << "\n"
      << "at " << lookAt.x << " " << lookAt.y << " " << lookAt.z << "\n"
      << "up " << up.x << " " << up.y << " " << up.z << "\n"
      << "angle " << angle << "\n"
      << "hither " << nearPlaneDist << "\n"
      << "resolution " << viewportSize.x << " " << viewportSize.y;
    
    return s.str();
}

/***************************************/
/**           CONSTRUCTORS            **/
/***************************************/
Camera::Camera()
: eye          (0.0f,0.0f,0.0f),
  lookAt       (0.0f,0.0f,-1.0f),
  up           (0.0f,1.0f,0.0f),
  angle        (90.0f),
  nearPlaneDist(0.1f),
  viewportSize (640,480)
{
}

Camera::Camera(
    glm::vec3  eye, 
    glm::vec3  lookAt,
    glm::vec3  up, 
    float      angle,
    float      nearPlaneDist,
    glm::ivec2 viewportSize
)
{
    this->eye           = eye;
    this->lookAt        = lookAt;
    this->up            = up;
    this->angle         = angle;
    this->nearPlaneDist = nearPlaneDist;
    this->viewportSize  = viewportSize;
}

Camera::~Camera()
{
}

/***************************************/
/**             GETTERS               **/
/***************************************/
glm::vec3 Camera::getEye(void)
{
    return eye;
}

glm::vec3 Camera::getLookAt(void)
{
    return lookAt;
}

glm::vec3 Camera::getUp(void)
{
    return up;
}

float Camera::getAngle(void)
{
    return angle;
}

float Camera::getNearPlaneDist(void)
{
    return nearPlaneDist;
}

glm::ivec2 Camera::getViewportSize(void)
{
    return viewportSize;
}

/***************************************/
/**             SETTERS               **/
/***************************************/
void Camera::setEye(glm::vec3 eye)
{
    this->eye = eye;
}
void Camera::setLookAt(glm::vec3 lookAt)
{
    this->lookAt = lookAt;
}
void Camera::setUp(glm::vec3 up)
{
    this->up = up;
}
void Camera::setAngle(float angle)
{
    this->angle = angle;
}
void Camera::setNearPlaneDist(float nearPlaneDist)
{
    this->nearPlaneDist = nearPlaneDist;
}
void Camera::setViewportSize(glm::ivec2 viewportSize)
{
    this->viewportSize = viewportSize;
}

