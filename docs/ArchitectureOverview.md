---
description: This is a custom description for this page
expanded: true
icon: ":rocket:"
label: Architecture Overview
title: Architecture Overview
---

## OtterLib Core

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
#### This class need to:
- [ ] Optimize the space the data take
- [ ] Optimize the speed witch it take to retrive and store
- [ ] Store many type of data
+ [ ] Give a user interface with the less boilerplating

