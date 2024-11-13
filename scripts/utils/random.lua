local random = {};

function random.int(min, max)
    return math.random(min, max);
end

function random.float(min, max)
    return min + math.random() * (max - min);
end

return random;