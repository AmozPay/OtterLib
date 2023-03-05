# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2023-03-05

### Added

#### OtterLib
- Add scriping possibilities with Lua: craete and delete entities, add and delete components, create systems
- New mandatory extern function: configureScripting
- baseComponents, that may be (and should) used in games
- OtterNetwork

#### R-Type
- Client and Server builds from same source
- enemies, collisions, etc
- parallax


## [0.3.0] - 2023-02-06

### Added

#### OtterCore
- Factorisable components from json file using COMPONENT_BUILDER

#### OtterCore
- R-type is now playable with player movements

#### OtterNetwork
- Network is now functionnal and cand send and receive data

## [0.2.0] - 2023-02-04

### Added

- OtterCore: Functional ECS Engine using some Otter magic :magic_wand:
- OtterGraphic: A graphic library using Raylib
- OtterNetwork: UDP Networking game library with it's own protocol
- r-type_client: An early development, cross-platform prototype game using the OtterLib as the engine
- r-type_server: r-type master server (prototype)

## [0.1.0] - 2023-01-11

### Added

- OtterLib libraries as a Hello World
- RType game as a Hello World

[1.0.0]: https://github.com/AmozPay/Otter-Type/releases/tag/v1.0.0
[0.2.0]: https://github.com/AmozPay/Otter-Type/releases/tag/v0.2.0
[0.1.0]: https://github.com/AmozPay/Otter-Type/releases/tag/v0.1.0

