OtterLib = {
    orchestrator = {
        createEntity = function() return __createEntity()end,
        removeEntity = function(entity) return __removeEntity(entity)end
    },
    components = {
        -- Nothing for Keyboard yet
        -- Nothing for Texture yet
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
            delete = function(entityInt) __Window_delete(entityInt) end,
            width = {
                set = function(entityInt, widthInt) __Window_set_width(entityInt, widthInt) end,
                get = function(entityInt) return __Window_get_width(entityInt) end,
            },
            height = {
                set = function(entityInt, heightInt) __Window_set_height(entityInt, heightInt) end,
                get = function(entityInt) return __Window_get_height(entityInt) end,
            },
            title = {
                set = function(entityInt, titleStr) __Window_set_title(entityInt, titleStr) end,
                get = function(entityInt) return __Window_get_title(entityInt) end,
            },
            fps = {
                set = function(entityInt, fpsInt) __Window_set_fps(entityInt, fpsInt) end,
                get = function(entityInt, fpsInt) return __Window_get_fps(entityInt, fpsInt) end,
            }
        },
        BoxCollider = {
            createAndAdd = function(entityInt, widthInt, heightInt) __BoxCollider_createAndAdd(entityInt, widthInt, heightInt) end,
            delete = function(entityInt) __BoxCollider_delete(entityInt) end,

            width = {
                set = function(entityInt, widthInt) __BoxCollider_set_width(entityInt, widthInt) end,
                get = function(entityInt) return __BoxCollider_get_width(entityInt) end,
            },
            height = {
                set = function(entityInt, heightInt) __BoxCollider_set_height(entityInt, heightInt) end,
                get = function(entityInt) return __BoxCollider_get_height(entityInt) end,
            },
        },
        Sound = {
            statusEnum = {
                PLAYING = "PLAYING",
                PAUSED = "PAUSED",
                STOPPED = "STOPPED",
            },
            createAndAdd = function(entityInt, pathStr, volumeFloat, SoundStatusEnum) __Sound_createAndAdd(entityInt, pathStr, volumeFloat, SoundStatusEnum) end,
            delete = function(entityInt) __Sound_delete(entityInt) end,

            path = {
                set = function(entityInt, pathStr) __Sound_set_path(entityInt, pathStr) end,
                get = function(entityInt, pathStr) return __Sound_get_path(entityInt, pathStr) end
            },
            volume = {
                set = function(entityInt, volumeFloat) __Sound_set_volume(entityInt, volumeFloat) end,
                get = function(entityInt, volumeFloat) return __Sound_get_volume(entityInt, volumeFloat) end
            },
            status = {
                set = function(entityInt, SoundStatusEnum) __Sound_set_status(entityInt, SoundStatusEnum) end,
                get = function(entityInt, SoundStatusEnum) return __Sound_get_status(entityInt, SoundStatusEnum) end,
            },
        },
        Music = {
            statusEnum = {
                PLAYING = "PLAYING",
                PAUSED = "PAUSED",
                STOPPED = "STOPPED",
            },
            createAndAdd = function(entityInt, pathStr, volumeFloat, isLoopingBool, MusicStatusEnum) __Music_createAndAdd(entityInt, pathStr, volumeFloat, isLoopingBool, isLoopingBool, MusicStatusEnum) end,
            delete = function(entityInt) __Music_delete(entityInt) end,

            path = {
                set = function(entityInt, pathStr) __Music_set_path(entityInt, pathStr) end,
                get = function(entityInt, pathStr) return __Music_get_path(entityInt, pathStr) end
            },
            volume = {
                set = function(entityInt, volumeFloat) __Music_set_volume(entityInt, volumeFloat) end,
                get = function(entityInt, volumeFloat) return __Music_get_volume(entityInt, volumeFloat) end
            },
            status = {
                set = function(entityInt, SoundStatusEnum) __Music_set_status(entityInt, SoundStatusEnum) end,
                get = function(entityInt, SoundStatusEnum) return __Music_get_status(entityInt, SoundStatusEnum) end,
            },
            isLooping = {
                set = function(entityInt, isLoopingBool) __Music_set_isLooping(entityInt, isLoopingBool) end,
                get = function(entityInt, isLoopingBool) return __Music_get_isLooping(entityInt, isLoopingBool) end,
            }
        },
        Transform = {
            createAndAdd = function(entityInt, scaleFloat, rotationFloat, xPosInt, yPosInt) __Transform_createAndAdd(entityInt, scaleFloat, rotationFloat, xPosInt, yPosInt) end,
            delete = function(entityInt) __Transform_delete(entityInt) end,
            rotation = {
                set = function(entityInt, rotationFloat) __Transform_set_rotation(entityInt, rotationFloat) end,
                get = function(entityInt) return __Transform_get_rotation(entityInt) end,
            },
            scale = {
                set = function(entityInt, scaleFloat) __Transform_set_scale(entityInt, scaleFloat) end,
                get = function(entityInt) return __Transform_get_scale(entityInt) end,
            },
            position = {
                set = function(entityInt, xInt, yInt) __Transform_set_position(entityInt, xInt, yInt) end,
                get = function(entityInt) return __Transform_get_position(entityInt) end,
            },
            lastPosition = {
                set = function(entityInt, xInt, yInt) __Transform_set_lastPosition(entityInt, xInt, yInt) end,
                get = function(entityInt) __Transform_get_lastPosition(entityInt) end,
            }
        },
        Velocity = {
            createAndAdd = function(entityInt, speedFloat, constantSpeedFloat, xPosInt, yPosInt) __Velocity_createAndAdd(entityInt, speedFloat, constantSpeedFloat, xPosInt, yPosInt) end,
            delete = function(entityInt) __Velocity_delete(entityInt) end,

            speed = {
                set = function(entityInt, speedFloat) __Velocity_set_speed(entityInt, speedFloat) end,
                get = function(entityInt) return __Velocity_get_speed(entityInt, speedFloat) end,

            },
            constantSpeed = {
                set = function(entityInt, constantSpeedFloat) __Velocity_set_constantSpeed(entityInt, constantSpeedFloat) end,
                get = function(entityInt) return __Velocity_get_constantSpeed(entityInt) end,
            },
            accelerationDirection = {
                set = function(entityInt, xInt, yInt) __Velocity_set_accelerationDirection(entityInt, xInt, yInt) end,
                get = function(entityInt) return __Velocity_get_accelerationDirection(entityInt) end,
            },
            constantAccelerationDirection = {
                set = function(entityInt, xInt, yInt) __Velocity_set_constantAccelerationDirection(entityInt, xInt, yInt) end,
                get = function(entityInt) return __Velocity_get_constantAccelerationDirection(entityInt) end,
            }
        },
        Player = {
            createAndAdd = function(entityInt, idInt, tagStr) __Player_createAndAdd(entityInt, idInt, tagStr) end,
            delete = function(entityInt) __Player_delete(entityInt) end,
            id = {
                set = function(entityInt, idInt) __Player_set_id(entityInt, idInt) end,
                get = function(entityInt) return __Player_get_id(entityInt) end,
            },
            tag = {
                set = function(entityInt, tagStr) __Player_set_tag(entityInt, tagStr) end,
                get = function(entityInt) return __Player_get_tag(entityInt) end,
            }
        },
        Enemy = {
            createAndAdd = function(entityInt, idInt, tagStr) __Enemy_createAndAdd(entityInt, idInt, tagStr) end,
            delete = function(entityInt) __Enemy_delete(entityInt) end,
            id = {
                set = function(entityInt, idInt) __Enemy_set_id(entityInt, idInt) end,
                get = function(entityInt) return __Enemy_get_id(entityInt) end,
            },
            tag = {
                set = function(entityInt, tagStr) __Enemy_set_tag(entityInt, tagStr) end,
                get = function(entityInt) return __Enemy_get_tag(entityInt) end,
            }
        },
        Health = {
            createAndAdd = function(entityInt, hpInt) __Health_createAndAdd(entityInt, hpInt) end,
            delete = function(entityInt) __Health_delete(entityInt) end,
            hp = {
                set = function(entityInt, hpInt) __Health_set_hp(entityInt, hpInt) end,
                get = function(entityInt) return __Health_get_hp(entityInt) end,
            }
        },
        Damage = {
            createAndAdd = function(entityInt, damageInt) __Damage_createAndAdd(entityInt, damageInt) end,
            delete = function(entityInt) __Damage_delete(entityInt) end,
            damage = {
                set = function(entityInt, damageInt) __Damage_set_damage(entityInt, damageInt) end,
                get = function(entityInt) return __Damage_get_damage(entityInt) end,
            }
        },
        Destructible = {
            createAndAdd = function(entityInt, isDestructibleBool) __Destructible_createAndAdd(entityInt, isDestructibleBool) end,
            delete = function(entityInt) __Destructible_delete(entityInt) end,
            IsDestructible = {
                set = function(entityInt, isDestructibleBool) __Destructible_set_isDestructible(entityInt, isDestructibleBool) end,
                get = function(entityInt) return __Destructible_get_isDestructible(entityInt) end,
            }
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
