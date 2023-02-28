local function createPlayer()
    playerEntity = OtterLib.orchestrator.createEntity()
    print(playerEntity)
    OtterLib.components.Player.createAndAdd(playerEntity, 5, "testPlayer")
    OtterLib.components.Health.createAndAdd(playerEntity, 200)
    hp = OtterLib.components.Health.hp.get(playerEntity)
    print(hp)
end

local function updatePlayerHealth()
    OtterLib.components.Health.hp.set(playerEntity, math.random(0, 100))
    print(OtterLib.components.Health.hp.get(playerEntity))
end



OtterLib.systems.register(createPlayer, OtterLib.systems.phasesEnum.init)
OtterLib.systems.register(updatePlayerHealth, OtterLib.systems.phasesEnum.update)
-- table.insert(OtterLib.systems.update, createSingleEntity)
