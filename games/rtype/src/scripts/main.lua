tps = 10
tick = 0

function logger()

end

table.insert(OtterSystems.init, logger)

-- local player = {
--     {
--         id = 5,
--         tag = "John Doe",
--     },
-- }



-- local function createPlayers()
--     local playerEntity = OtterLib.orchestrator.createEntity()
--     OtterLib.components.Player.createAndAdd(playerEntity, player["id"], player["tag"])
--     OtterLib.components.Velocity.createAndAdd(playerEntity, 0, 0, 1, 10)
--     OtterLib.components.BoxCollider.createAndAdd(playerEntity, 96, 42)
--     OtterLib.components.Health.createAndAdd(playerEntity, 100)
--     player["entityId"] = playerEntity
-- end

-- local function createEntities()
--     createPlayers()
-- end

-- local function updatePlayers()
--     for index, value in pairs(players) do
--         print("Player " .. OtterLib.components.Player.tag.get(value["entityId"]) .. ":")
--         print("Hp: " .. OtterLib.components.Health.hp.get(value["entityId"]))
--         print("\n")
--     end
-- end


-- OtterLib.systems.register(createEntities, OtterLib.systems.phasesEnum.init)
-- OtterLib.systems.register(updatePlayers, OtterLib.systems.phasesEnum.update)
-- -- table.insert(OtterLib.systems.update, createSingleEntity)
