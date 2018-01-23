#include "Alien.h"


Alien::Alien (vec3 position)            //Alien Constructor
{
	AlienTransformB.SetPos(position);              //Sets the Aliens Position
	AlienTransformB.SetScale(vec3(3,3,3));         //Sets the Aliens Scale
	AlienTransformB.GetRot().y =270;               //Sets the Aliens Rotation
}

Alien::~Alien()        //Alien Deconstructor
{
}

void Alien::Update()          //Updates the Aliens Position
{ 
	AlienTransformB.GetPos().z -= 0.6f;     // Moves the Alien towards the Player
	
}

bool Alien::CollisionDetectionMethod(vec3 mdlPos, float mdlRadius)         // Collision Detection for the Alien
{
	const float distanceSq = FindLength(AlienTransformB.GetPos() - mdlPos);    //Finds the Length squared of the Alien Object
	const float sumRadius = (7.5f + mdlRadius);                                //Finds the Aliens Radius 

	if (distanceSq < sumRadius * sumRadius)                                    //If the Length is less than the Other models Radius 
	{
		return true;                                                           //The objects have collided
	}
	return false;                                                              //Otherwise no Collison has been detected
}

float Alien::FindLength(vec3(ObjectLength))                                    //Finds the length of the Alien Model
{
	return (ObjectLength.x*ObjectLength.x) + (ObjectLength.y*ObjectLength.y) + (ObjectLength.z*ObjectLength.z);
}