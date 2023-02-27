OtterLib = {
    orchestrator = {
        createEntity = function() return __createEntity()end,
        removeEntity = function(entity) return __removeEntity(entity)end
    },
    components = {
        -- Nothing for Keyboard yet
        Render = {
            createAndAdd = function(entityInt) __Render_createAndAdd(entityInt) end,
            delete = function(entityInt) __Render_delete(entityInt) end,
        },
        Dispawnable = {
            createAndAdd = function(entityInt) __Dispawnable_createAndAdd(entityInt) end,
            delete = function(entityInt) __Dispawnable_delete(entityInt) end,
        },
        Parallax = {
            createAndAdd = function(entityInt) __Parallax_createAndAdd(entityInt) end,
            delete = function(entityInt) __Parallax_delete(entityInt) end,
        },
        EventNetwork = {
            createAndAdd = function(entityInt) __EventNetwork_createAndAdd(entityInt) end,
            delete = function(entityInt) __EventNetwork_delete(entityInt) end,
        },
        Window = {
            createAndAdd = function(entityInt, widthInt, heightInt, titleStr, fpsInt) __Window_createAndAdd(entityInt,widthInt, heightInt, titleStr, fpsInt) end,
            setWidth = function(entityInt, widthInt) __Window_setWidth(entityInt, widthInt) end,
            setHeight = function(entityInt, heightInt) __Window_setHeight(entityInt, heightInt) end,
            setTitle = function(entityInt, titleStr) __Window_setTitle(entityInt, titleStr) end,
            setFps = function(entityInt, fpsInt) __Window_setFps(entityInt, fpsInt) end,
            delete = function(entityInt) __Window_delete(entityInt) end
        },
        BoxCollider = {
            createAndAdd = function(entityInt, widthInt, heightInt) __BoxCollider_createAndAdd(entityInt, widthInt, heightInt) end,
            setWidth = function(entityInt, widthInt) __BoxCollider_setWidth(entityInt, widthInt) end,
            setHeight = function(entityInt, heightInt) __BoxCollider_setHeight(entityInt, heightInt) end,
            delete = function(entityInt) __BoxCollider_delete(entityInt) end
        },
        Sound = {
            statusEnum = {
                PLAYING = "PLAYING",
                PAUSED = "PAUSED",
                STOPPED = "STOPPED",
            },
            createAndAdd = function(entityInt, pathStr, volumeFloat, SoundStatusEnum) __Sound_createAndAdd(entityInt, pathStr, volumeFloat, SoundStatusEnum) end,
            setPath = function(entityInt, pathStr) __Sound_setPath(entityInt, pathStr) end,
            setVolume = function(entityInt, volumeFloat) __Sound_setVolume(entityInt, volumeFloat) end,
            setStatus = function(entityInt, SoundStatusEnum) __Sound_setStatus(entityInt, SoundStatusEnum) end,
            delete = function(entityInt) __Sound_delete(entityInt) end
        },
        Music = {
            statusEnum = {
                PLAYING = "PLAYING",
                PAUSED = "PAUSED",
                STOPPED = "STOPPED",
            },
            createAndAdd = function(entityInt, pathStr, volumeFloat, isLoopingBool, MusicStatusEnum) __Music_createAndAdd(entityInt, pathStr, volumeFloat, isLoopingBool, isLoopingBool, MusicStatusEnum) end,
            setPath = function(entityInt, pathStr) __Music_setPath(entityInt, pathStr) end,
            setVolume = function(entityInt, volumeFloat) __Music_setVolume(entityInt, volumeFloat) end,
            setIsLooping = function(entityInt, isLoopingBool) __Music_setIsLooping(entityInt, isLoopingBool) end,
            delete = function(entityInt) __Music_delete(entityInt) end
        },
        Transform = {
            createAndAdd = function(entityInt, scaleFloat, rotationFloat, xPosInt, yPosInt) __Transform_createAndAdd(entityInt, scaleFloat, rotationFloat, xPosInt, yPosInt) end,
            setRotation = function(entityInt, rotationFloat) __Transform_setRotation(entityInt, rotationFloat) end,
            setScale = function(entityInt, scaleFloat) __Transform_setScale(entityInt, scaleFloat) end,
            setPosition = function(entityInt, xInt, yInt) __Transform_setPosition(entityInt, xInt, yInt) end,
            setLastPosition = function(entityInt, xInt, yInt) __Transform_setLastPosition(entityInt, xInt, yInt) end,
            delete = function(entityInt) __Transform_delete(entityInt) end,
        },
        Velocity = {
            createAndAdd = function(entityInt, speedFloat, constantSpeedFloat, xPosInt, yPosInt) __Velocity_createAndAdd(entityInt, speedFloat, constantSpeedFloat, xPosInt, yPosInt) end,
            setSpeed = function(entityInt, speedFloat) __Velocity_setSpeed(entityInt, speedFloat) end,
            setConstantSpeed = function(entityInt, constantSpeedFloat) __Velocity_setConstantSpeed(entityInt, constantSpeedFloat) end,
            setAccelerationDirection = function(entityInt, xInt, yInt) __Velocity_setAccelerationDirection(entityInt, xInt, yInt) end,
            setConstantAccelerationDirection = function(entityInt, xInt, yInt) __Velocity_setConstantAccelerationDirection(entityInt, xInt, yInt) end,
            delete = function(entityInt) __Velocity_delete(entityInt) end,
        },
        Player = {
            createAndAdd = function(entityInt, idInt, tagStr) __Player_createAndAdd(entityInt, idInt, tagStr) end,
            setId = function(entityInt, idInt) __Player_setId(entityInt, idInt) end,
            setTag = function(entityInt, tagStr) __Player_setTag(entityInt, tagStr) end,
            delete = function(entityInt) __Player_delete(entityInt) end,
        },
        Enemy = {
            createAndAdd = function(entityInt, idInt, tagStr) __Enemy_createAndAdd(entityInt, idInt, tagStr) end,
            setId = function(entityInt, idInt) __Enemy_setId(entityInt, idInt) end,
            setTag = function(entityInt, tagStr) __Enemy_setTag(entityInt, tagStr) end,
            delete = function(entityInt) __Enemy_delete(entityInt) end,
        },
        Health = {
            createAndAdd = function(entityInt, hpInt) __Health_createAndAdd(entityInt, hpInt) end,
            setHp = function(entityInt, hpInt) __Health_setHp(entityInt, hpInt) end,
            delete = function(entityInt) __Health_delete(entityInt) end,
        },
        Damage = {
            createAndAdd = function(entityInt, damageInt) __Damage_createAndAdd(entityInt, damageInt) end,
            setDamage = function(entityInt, damageInt) __Damage_setDamage(entityInt, damageInt) end,
            delete = function(entityInt) __Damage_delete(entityInt) end,
        },
        Destructible = {
            createAndAdd = function(entityInt, isDestructibleBool) __Destructible_createAndAdd(entityInt, isDestructibleBool) end,
            setIsDestructible = function(entityInt, isDestructibleBool) __Destructible_setIsDestructible(entityInt, isDestructibleBool) end,
            delete = function(entityInt) __Destructible_delete(entityInt) end,
        },
    },
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

print("[OtterLib] Lua Module loaded")
