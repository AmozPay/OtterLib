players = {
    {
        id = 5,
        tag = "John Doe",
    },
    {
        id = 6,
        tag = "Lucas Stagnette"
    }
}



local function createPlayers()
    -- for index, value in pairs(players) do
    --     local playerEntity = OtterLib.orchestrator.createEntity()
    --     OtterLib.components.Player.createAndAdd(playerEntity, value["id"], value["tag"])
    --     OtterLib.components.Health.createAndAdd(playerEntity, 200)
    --     value["entityId"] = playerEntity
    end
end

local function createEntities()
    createPlayers()
end

local function updatePlayers()
    -- for index, value in pairs(players) do
    --     print("Player " .. OtterLib.components.Player.tag.get(value["entityId"]) .. ":")
    --     print("Hp: " .. OtterLib.components.Health.hp.get(value["entityId"]))
    --     print("\n")
    end
end



OtterLib.systems.register(createEntities, OtterLib.systems.phasesEnum.init)
OtterLib.systems.register(updatePlayers, OtterLib.systems.phasesEnum.update)
-- table.insert(OtterLib.systems.update, createSingleEntity)
