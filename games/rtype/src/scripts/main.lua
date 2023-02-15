
tps = 10
tick = 0

function logger()
    if (tick % tps == 0)
    then
        print("[" .. tick .. "] hi dude")
    end
    tick = tick + 1
end

table.insert(OtterSystems.init, logger)

