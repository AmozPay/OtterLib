---
description: This is a custom description for this page
expanded: true
label: Architecture Overview
title: Architecture Overview
---

The OtterLib is composed of different static libraries:
- OtterCore
- OtterNetwork
- OtterGraphic

In this section, we'll fly over the OtterCore architecture, which will allow you to create game components and their behavior.

## Core composition

```mermaid
classDiagram

class OtterCore
class Orchestrator
class SystemManager
class Factory
class EntityManager
class ComponentManager
class sparse_array
class light_array


OtterCore "1" *-- Factory
OtterCore "1" *-- Orchestrator
OtterCore "1" *-- SystemManager

Orchestrator "1" o-- Factory
Orchestrator "1" *-- EntityManager
Orchestrator "1" *-- ComponentManager

ComponentManager "many" *-- sparse_array
ComponentManager "many" *-- light_array

OtterCore : -init()
OtterCore : +engineStart()int
OtterCore : +registerComponents()
OtterCore : +registerSystem()

class Orchestrator {
createEntity()Entity

 +register_component()sparse_array~C~

 +get_components()sparse_array~C~


+add_component(Entity const &add, C&& component)optional~C~

+remove_component(Entity const&)
+remove_entity(Entity const &)
}

class sparse_array {
+operator[](size_t)reference_type
+size()size_type
+insert_at(size_type, C const&)reference_type
+isEmpty()bool
+erase(size_type)
+get_index(optional~C~ const &)size_type
}

class EntityManager {
+CreateEntity()Entity
+destroyEntity(Entity)
}

class SystemManager {
+registerSystem(F &&, Phase)
+operator(Orchestrator &, Phase)
}

class Factory {
+createFromFile(path, Orchestrator&)Entity
loadEntitiesFromFolder(path, Orchestrator&)vector~Entity~
}

```

# Core Details

### the core is made of many part; the essential one are:
- dataManagement (storing game data)
- Execution of function/script (system)
- Factory to create scene of object without touching the code base
- Abstraction of the EndPoint

## DataManagement
### In short, A class who store data and give methode to retrieve them when needed.
#### This class:
- [ ] Optimize the space the data take
- [ ] Optimize the speed witch it take to retrive and store
- [ ] Store many type of data
+ [ ] Give a user interface with the less boilerplating

#### Implementation
- The same data are stored in optized a storage
  - > see sparse_array

- Each group of data are stored in a generic way
  - > see component_manager

- Each data are assigned/linked to an Id (entity)
  - > see EntityManager

- All fonctionality a centralize in a user friendly interface
  - > see Orchestrator
## Execution of function/script
### In short, this is the part who run function in a order to permit the game to run.
the fonction are write by the game developer and register in the engine.
> Here  - How to create a system -
## Factory
### A Class implementing a factory from json giving right to creating ensemble of object without coding
  2 ways of creating object:
  * creating from a file
  * creating from folder

## abstract
### main
the main is already implemented.
Actualy the main use 2 fonction who need to be implement by game developpeur
   - registerComponents
>function where we register all component who will be used
   - registerSystems
>function where we register all system who will be used
### Base loop
Implement a actual loop 












```mermaid
sequenceDiagram
	Graphique->>ClientCore: Event detected
	ClientCore->>ClientNetwork: push message
	ClientNetwork-->ServerNetwork:Bit comunication
	ClientCore->>ClientNetwork: push RPC
	ClientNetwork-->ServerNetwork:Bit comunication
	ClientCore->>Graphique: DrawMe something
	ClientNetwork-->ServerNetwork:Bit comunication
	ServerNetwork ->> ServerCore:Recieving mesage
	ClientNetwork-->ServerNetwork:Bit comunication
	ServerNetwork ->> ServerCore:Recieving RPC
	ClientNetwork-->ServerNetwork:Bit comunication
	ServerCore->>ServerNetwork: Push Verified Updated Component
	ClientNetwork->>ClientCore: Receive Autorirator update
	ClientCore->>Graphique: DrawMe something
 	
```

![](../../assets/images/lovu_otter.png)


```C++
int main() {
}```