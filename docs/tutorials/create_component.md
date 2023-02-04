---
description: Tutorial for creating a component
expanded: true
label: Creating a component
icon: tools
---

### Definition

A component is a simple class type with data, a constructor, destructor, and other methode to optimaze.   
Can use also other type of storage like struct or simple type.

A composant represent a part of a object. And a object is create by a ensemble a composants.
A composant don't implement logic but only data to be stored and used but in itself he can be used to define if a Entity posses or not a property.

The used of the composant is varied and depend of the user, So be creative!!
### Let's practice

You know now what is a composant and is basic use. but what is real aplication.

Let define some composant that we will use in the next chapter:
- a Transform -> represent the position in diferent aspect of a object (in 3d)
- a Player -> is used more for define a entity with the tag player than a generic purpose
- a Velocity -> represent the moving variation when accelerating and slowing.

``` C++
class Transform {
public:
	int x;
	int y;
	int z;

	Transform(int, int, int);
	~Transform();
	...
	vector<int> conver_to_vector();
}

struct Player{
public:
	std::string name;
	int id;
	Player(int, std::string);
	~Player();
	...
}

class Velocity{
public:
	float speed;
	int x_dir;
	int y_dir;
	Velocity(float basespeed);
	~Velocity();

	void setDir(int, int);
	void setSpeed(flaot);
	...
}

```
> See Also Factory/Buildable composant

> See Also Network/Neworkable Variable
