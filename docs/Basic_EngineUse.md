--
description: tutorial for base game dev
expanded: true
label: tutoriel
title: base game dev
---

# Tutorial

## Tools

## Create a Component
A simple class type with data, a constructor, destructor, and other methode to optimaze.

Can use also other type of storage like struct or simple type.

``` C++

class Transform {
public:
	int x;
	int y;
	int z;

	Transform(int, int, int);
	...

	vector<int> conver_to_vector();

	...

}
```
> See Also Factoru/Buildable composant

> See Also Network/Neworkable Variable
## Create a System
A system is a single function, So it can be:
- a lambda
- a primive function
- a operator() methode
but It need to have this prototype ```void ()(Orchestrator &);```

When writing your system you will need to get data from the core.
For this use the public methode _get_component()_ with the type of component you want in the template params.
Next store the result in a Sparse_array<>& (same type as the get).

nice you get the component list, now is time to use them.
So we start by iterating on them and test if they exist.

if the condition a complite we execut some logical computing

```c++

void shoot_system(... &data)
{
 auto const &player = data.get_components<component::Player>();
 auto const &event = ...
 auto const

 if (event[0].shooting) {
   for (int i = 0; player.size() != i; i++) {
       if (player[i])
       	  if (player[i].bulletNbr < 2)
	     shoot_some(data, bullet, player[i], i);

   }
 }
}

void shoot_some(... &data, ... &bullet, ... &player, ... id)
{
 auto const &bullet = data.get_components<component::Bullet>();
 auto const &transform = data.get_components<component::transform>();
 auto const &dmg = data.get_components<component::stat>();

for (...) {
    if (bullet[i]){
       if (bullet[i].isOut()) {
          transform[i] = tranform[id];
          bullet[i].setCreator(player.id_player);
          dmg[i].dmg = dmg[id].dmg
          return;
	  }
	}
    }
    auto &newEntity = data.createEntity();
    data.add_Component(newEntity, composant::stat(dmg[id]));
    data.add_Component(newEntity, composant::bullet(player.id_player, true));
    ... 	      (newEntity, composant::transform(transform[id]))
    return;
}

```



## Integration
