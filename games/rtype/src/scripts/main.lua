local function createAndDeleteEntity()
    local a = OtterLib.orchestrator.createEntity()
    print("Entity created: ")
    print(a)
    -- OtterLib.orchestrator.removeEntity(a)
    -- print("Entity deleted")
end





table.insert(OtterLib.systems.update, createAndDeleteEntity)
-- table.insert(OtterLib.systems.update, createSingleEntity)
