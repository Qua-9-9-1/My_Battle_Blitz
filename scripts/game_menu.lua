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
    miniGame.sprite = Sprite.new(miniGame.image:getImage());
    miniGame.text = Text.new("Free Projects", "assets/font/Mario-Kart-DS.ttf");
    miniGame.sound = Sound.new("assets/sounds/random.ogg");
    miniGame.music = Music.new("assets/music/menu.ogg");
    miniGame.showdown_button = Button.new("SHOWDOWN", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.freeplay_button = Button.new("FREEPLAY", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.controls_button = Button.new("CONTROLS", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.settings_button = Button.new("SETTINGS", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.credits_button = Button.new("CREDITS", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.exit_button = Button.new("QUIT", "assets/font/Mario-Kart-DS.ttf", 200, 200);

    miniGame.showdown_button:setSize(70);
    miniGame.showdown_button:setPadding(30, 30);
    miniGame.showdown_button:setColor(0, 0, 0, 255);
    miniGame.showdown_button:setBorderColor(255, 255, 255, 255);
    miniGame.showdown_button:setTextColor(255, 255, 255, 255);
    miniGame.showdown_button:setPosition(400, 100);
    miniGame.freeplay_button:setSize(70);
    miniGame.freeplay_button:setPadding(30, 30);
    miniGame.freeplay_button:setColor(0, 0, 0, 255);
    miniGame.freeplay_button:setBorderColor(255, 255, 255, 255);
    miniGame.freeplay_button:setTextColor(255, 255, 255, 255);
    miniGame.freeplay_button:setPosition(400, 300);
    miniGame.controls_button:setSize(70);
    miniGame.controls_button:setPadding(30, 30);
    miniGame.controls_button:setColor(0, 0, 0, 255);
    miniGame.controls_button:setBorderColor(255, 255, 255, 255);
    miniGame.controls_button:setTextColor(255, 255, 255, 255);
    miniGame.controls_button:setPosition(400, 500);
    miniGame.settings_button:setSize(50);
    miniGame.settings_button:setPadding(30, 30);
    miniGame.settings_button:setColor(0, 0, 0, 255);
    miniGame.settings_button:setBorderColor(255, 255, 255, 255);
    miniGame.settings_button:setTextColor(255, 255, 255, 255);
    miniGame.settings_button:setPosition(50, 700);
    miniGame.credits_button:setSize(50);
    miniGame.credits_button:setPadding(30, 30);
    miniGame.credits_button:setColor(0, 0, 0, 255);
    miniGame.credits_button:setBorderColor(245, 245, 255, 255);
    miniGame.credits_button:setTextColor(245, 245, 255, 255);
    miniGame.credits_button:setPosition(400, 700);
    miniGame.exit_button:setSize(50);
    miniGame.exit_button:setPadding(30, 30);
    miniGame.exit_button:setColor(0, 0, 0, 255);
    miniGame.exit_button:setBorderColor(220, 0, 0, 255);
    miniGame.exit_button:setTextColor(220, 0, 0, 255);
    miniGame.exit_button:setPosition(750, 700);
    miniGame.sprite:setPosition(400, 200);
    miniGame.sprite:setScale(2, 2);
    miniGame.text:setPosition(0, 0);
    miniGame.music:play();
    miniGame.music:setReplayPoint(6);
    return true;
end

function update(window, deltaTime)
    miniGame.sprite:update(window);
    miniGame.music:update(window);
    miniGame.showdown_button:update(window);
    miniGame.freeplay_button:update(window);
    miniGame.controls_button:update(window);
    miniGame.settings_button:update(window);
    miniGame.credits_button:update(window);
    miniGame.exit_button:update(window);
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
