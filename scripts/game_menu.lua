--/
-- Quentin Duval 2024
-- Free Projects
-- GitHub: @Qua-9-9-1
-- Email:  quentduva@gmail.com
--\

local miniGame = {
    image = nil,
    sprite = nil;
    text = nil;
    sound = nil;
    freeplay_button = nil;
    showdown_button = nil;
    settings_button = nil;
    exit_button = nil;
    controls_button = nil;
    credits_button = nil;
    music = nil;
    cursor = nil;
    select = nil;
    switch_player = nil;
};

function init()
    miniGame.image = Image.new("assets/sprites/game_logo.png");
    if not miniGame.image then
        return false;
    end
    miniGame.sprite = Sprite.new(miniGame.image:getImage());
    if not miniGame.sprite then
        return false;
    end
    miniGame.text = Text.new("Free Projects", "assets/font/Mario-Kart-DS.ttf");
    if not miniGame.text then
        return false;
    end
    miniGame.sound = Sound.new("assets/sounds/random.ogg");
    if not miniGame.sound then
        return false;
    end
    miniGame.music = Music.new("assets/music/menu.ogg");
    if not miniGame.music then
        return false;
    end
    miniGame.sprite:setPosition(300, 100);
    miniGame.sprite:setScale(2, 2);
    miniGame.text:setPosition(0, 0);
    miniGame.music:setReplayPoint(6);
    -- miniGame.music:play();
    return true;
end

function update(window, deltaTime)
    miniGame.sprite:update(window);
    miniGame.music:update(window);
end

function on_P1_left()
    print("P1 left")
end

function on_P1_right()
    print("P1 right")
end

function on_P1_up()
    print("P1 up")
end

function on_P1_down()
    print("P1 down")
end

function on_P1_1()
    miniGame.sound:play();
end

function on_P1_2()
    print("P1 action")
end

function on_P1_3()
    print("P1 action")
end

function on_P2_left()
    print("P1 action")
end

function on_P2_right()
    print("P1 action")
end

function on_P2_up()
    print("P1 action")
end

function on_P2_down()
    print("P1 action")
end

function on_P2_1()
    print("P1 action")
end

function on_P2_2()
    print("P1 action")
end

function on_P2_3()
    print("P1 action")
end
