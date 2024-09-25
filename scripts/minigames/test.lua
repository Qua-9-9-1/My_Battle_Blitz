
local image = nil;
local sprite = nil;

function Init()
    image = Image.new("assets/sprites/sticks.png");
    image:flipImage(true, true);
    print("Image loaded")
    sprite = Sprite.new(image:getImage());
    print("Init")
end

function Update(window, deltaTime)
    sprite:update(window, deltaTime)
end


function Draw()
end