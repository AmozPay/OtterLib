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

class Orchestrator
class SystemManager
class EntityManager
class ComponentManager
class sparse_array
class light_array

Orchestrator *-- SystemManager
Orchestrator *-- EntityManager
Orchestrator *-- ComponentManager

Orchestrator : -SystemManager _system_manager


```