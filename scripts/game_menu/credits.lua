local credits = {};

local objects = {
    picture = nil;
    picture_sprite = nil;
    logo_image = nil;
    logo_sprite = nil;
    music = nil;
}

function credits.init()
    objects.picture = Image.new("assets/sprites/creator.jpg");
    objects.picture_sprite = Sprite.new(objects.picture:getImage());
    objects.picture_sprite:setPosition(400, 300);
    objects.picture_sprite:setScale(3, 3);
    objects.logo_image = Image.new("assets/sprites/game_logo.png");
    objects.logo_sprite = Sprite.new(objects.logo_image:getImage());
    objects.logo_sprite:setPosition(50, 50);
end

function credits.update(window, deltaTime)
    objects.picture_sprite:draw(window);
    objects.logo_sprite:draw(window);
    objects.logo_sprite:rotate(1);
end

function credits.accelerate()
    objects.picture_sprite:move(0, -5);
end

function credits.quit(miniGame)
    miniGame.location = 0;
end

return credits;