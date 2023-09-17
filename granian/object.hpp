#include <SFML/Graphics.hpp>
#include <string>
#include "settings.hpp"
#include "vector.hpp"
#include <math.h>
const double G = 6.67 / (pow(10, -11));

class object
{
public:
	object();
	object(vector baseVelocity, Vector2 position, double mass);
	sf::CircleShape* getShape();
	void update(object obj);
	float getMass();
	~object();

private:
	double mass; // kt
	sf::CircleShape* shape;
	vector velocity; // m/s
};

sf::CircleShape *object::getShape()
{
	return this->shape;
}

void object::update(object obj)
{
	// assuming (1/FPS) seconds have passed

	// update position
	this->shape->setPosition(this->shape->getPosition().x + (cosf(this->velocity.direction) * (this->velocity.magnitude / 1000000)) / refreshRate, // update x position
		this->shape->getPosition().y + (sinf(this->velocity.direction) * this->velocity.magnitude / 1000000) / refreshRate); // update y position

	// distance between the two objects
	double distObj = sqrtf(pow(obj.getShape()->getPosition().x - this->shape->getPosition().x, 2) + pow(obj.getShape()->getPosition().y - this->shape->getPosition().y, 2));
	
	// get Fg via F = g * (m1m2) / d2
	double ForceGravity = 0.000000000066743 * ((obj.getMass() * this->mass / 1000000) / (distObj * distObj));

	// get a via F = m * a
	double acceleration = (ForceGravity / this->mass) / 1000;
	
	//std::cout << ForceGravity <<'\n';
	double direction = atan2f((obj.getShape()->getPosition().y - this->shape->getPosition().y) , (obj.getShape()->getPosition().x - this->shape->getPosition().x));
	//std::cout << (this->shape->getPosition().x) << ", " << this->shape->getPosition().y << "    " << obj.getShape()->getPosition().x << ", " << obj.getShape()->getPosition().y;
	//std::cout << "  " << direction << '\n';
	//std::cout << this->shape->getPosition().y - obj.getShape()->getPosition().y << "     " << this->shape->getPosition().x - obj.getShape()->getPosition().x << '\n';
	//std::cout << direction << '\n';
	//vector(acceleration, direction).print();

	//this->velocity.print();
	this->velocity = vector(acceleration / refreshRate, direction) + this->velocity;
	//this->velocity.print();



}

float object::getMass()
{
	return this->mass;
}

object::object()
{
	this->shape = new sf::CircleShape(20);
}

object::object(vector baseVelocity, Vector2 position, double mass)
{
	this->mass = mass;
	//std::cout << baseVelocity.direction;
	this->velocity = vector(baseVelocity.magnitude, -baseVelocity.direction);
	this->shape = new sf::CircleShape(20);
	this->shape->setPosition(position.x, position.y);
}

object::~object()
{
}

