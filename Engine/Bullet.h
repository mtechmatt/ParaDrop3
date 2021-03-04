
#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Colors.h"
#include <math.h>

class Bullet
{

public:
	void Update(float dt);			//Updates the bullet (position, impact check etc)
	void Create(int inposX, int inposY, int firingAngle); //the starting point for the bullet (gun tip usually) and the firing angle to travel along
	void Draw(Graphics& gfx) const;
public:
	//Location locBullet;		//Every bullet has a location
	bool isActive = false;  //Should this bullet be updated/displayed/travelling?  
	float posX;
	float posY;
private:

	float velX;			//Velocity in the X direction
	float velY;			//Velocity in the Y direction
	int velMultiplier = 250;  //A mupltier we can mess with
};