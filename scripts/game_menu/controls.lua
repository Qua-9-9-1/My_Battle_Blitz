local controls = {};

local objects = {
    player_image = nil;
    p1_sprite = nil;
    p2_sprite = nil;
    action_sound = nil;
}

function controls.init()
    objects.player_image = Image.new("assets/sprites/control_test.png");
    -- objects.player_image:colorize(255, 255, 255, 255);
    objects.p1_sprite = Sprite.new(objects.player_image:getImage());
    objects.p1_sprite:setTextureRect(0, 0, 32, 32);
    objects.p1_sprite:setPosition(200, 300);
    -- objects.player_image:colorize(255, 255, 255, 255);
    objects.p2_sprite = Sprite.new(objects.player_image:getImage());
    objects.p2_sprite:setPosition(600, 300);
    objects.p2_sprite:setTextureRect(32, 0, 32, 32);
    objects.action_sound = Sound.new("assets/sounds/action.wav");
end


function controls.update(window)
    objects.p1_sprite:draw(window);
    objects.p2_sprite:draw(window);
    print("controls");
end
        
function controls.move_p1_left()
    objects.p1_sprite:setTextureRect(0, 0, 32, 32);
    objects.p1_sprite:move(-5, 0);
end

function controls.move_p1_right()
    objects.p1_sprite:setTextureRect(32, 0, 32, 32);
    objects.p1_sprite:move(5, 0);
end

function controls.move_p1_up()
    objects.p1_sprite:setTextureRect(64, 0, 32, 32);
    objects.p1_sprite:move(0, -5);
end

function controls.move_p1_down()
    objects.p1_sprite:setTextureRect(96, 0, 32, 32);
    objects.p1_sprite:move(0, 5);
end

function controls.action_A_p1()
    objects.action_sound:play();
end

function controls.action_B_p1()
    objects.action_sound:play();
end

function controls.action_C_p1()
    objects.action_sound:play();
end

function controls.move_p2_left()
    objects.p2_sprite:setTextureRect(0, 0, 32, 32);
    objects.p2_sprite:move(-5, 0);
end

function controls.move_p2_right()
    objects.p2_sprite:setTextureRect(32, 0, 32, 32);
    objects.p2_sprite:move(5, 0);
end

function controls.move_p2_up()
    objects.p2_sprite:setTextureRect(64, 0, 32, 32);
    objects.p2_sprite:move(0, -5);
end

function controls.move_p2_down()
    objects.p2_sprite:setTextureRect(96, 0, 32, 32);
    objects.p2_sprite:move(0, 5);
end

function controls.action_A_p2()
    objects.action_sound:play();
end

function controls.action_B_p2()
    objects.action_sound:play();
end

function controls.action_C_p2()
    objects.action_sound:play();
end

return controls