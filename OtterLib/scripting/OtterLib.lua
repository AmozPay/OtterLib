OtterLib = {
    orchestrator = {},
    systems = {
        init = {},
        preEvent = {},
        event = {},
        preUpdate = {},
        update = {},
        preDraw = {},
        draw = {},
        subDraw = {},
        cleanup = {}
    }
}

function OtterLib.orchestrator.createEntity()
    return __createEntity()
end

function OtterLib.orchestrator.removeEntity(entity)
    return __removeEntity(entity)
end

print("[OtterLib] Lua Module loaded")
