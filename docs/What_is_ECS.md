---
description: humm
expanded:true
icon: "sparkle"
label: ECS
title: What is a ECS
---

# ECS
A Ecs is a concept used for develop game with a more efficient way.
Where a object don't store is data and fonction but only refer to them. Letting the place to store optimalment the data
## Definition
A **ECS** is a concept of game engine where we split a game into 4 Part:

`Entity`,`Components`, `System` and the engine/core.

Each element in the game is a ensemble of this 4 part.

> - A basic element is a unique `Entity`.
> - Is propriete and data are difined in the `components` linked to is `Entity`
> - Each Entity are update when they posses a `composant` update by a `system`
> - a Core who manage/union all of the other
## Entity
A entity not composed of composant but insted represent a class ID for searching all composant associed.
## Components
A composant is a data struct where we only put data and method to manage them in simple way.

Each Component are stored by type. in a Giant array for optimaz the loading of data.
## System
A System is A function. (can be any type of fucntion)   
It don't update a Entity in specific but a ensemble of Composant. in this way we generalise the comportement of the object need and create a fewer function to update them with logical.

The system respect the concept of functionnel and only do one task.
> ex: Moving system, he apply the velocity to the trasform
this system only do this to all the composant available

