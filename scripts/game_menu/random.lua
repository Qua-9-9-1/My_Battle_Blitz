
local module = {};

function module.int(min, max)
    return math.random(min, max)
end

function module.float(min, max)
    return min + math.random() * (max - min)
end

return module