--/
-- Quentin Duval 2024
-- Free Projects
-- GitHub: @Qua-9-9-1
-- Email:  quentduva@gmail.com
--\

local WINDOW_WIDTH = 800
local WINDOW_HEIGHT = 600

-- local random_int = require("utils.random").randomInt
-- local random_float = require("utils.random").randomFloat

local miniGame = {
    image = nil,
    menu_sprite = nil;
    sound = nil;
    text = nil;
    background = nil;
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
    p1_pause = false;
    p2_pause = false;
    p1_leads = true;
    main_menu = true;
    credits_menu = false;
    freeplay_menu = false;
    showdown_menu = false;
    settings_menu = false;
};

function buttons_init()
    miniGame.showdown_button = Button.new("SHOWDOWN", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.showdown_button:setTextSize(70);
    miniGame.showdown_button:setSize(480, 100);
    miniGame.showdown_button:setColor(0, 0, 0, 255);
    miniGame.showdown_button:setBorderColor(255, 255, 255, 255);
    miniGame.showdown_button:setTextColor(255, 255, 255, 255);
    miniGame.showdown_button:setPosition(400, 130);
    
    miniGame.freeplay_button = Button.new("FREEPLAY", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.freeplay_button:setTextSize(70);
    miniGame.freeplay_button:setSize(480, 100);
    miniGame.freeplay_button:setColor(0, 0, 0, 255);
    miniGame.freeplay_button:setBorderColor(255, 255, 255, 255);
    miniGame.freeplay_button:setTextColor(255, 255, 255, 255);
    miniGame.freeplay_button:setPosition(400, 280);
    
    miniGame.controls_button = Button.new("CONTROLS", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.controls_button:setTextSize(70);
    miniGame.controls_button:setSize(480, 100);
    miniGame.controls_button:setColor(0, 0, 0, 255);
    miniGame.controls_button:setBorderColor(255, 255, 255, 255);
    miniGame.controls_button:setTextColor(255, 255, 255, 255);
    miniGame.controls_button:setPosition(400, 430);
    
    miniGame.settings_button = Button.new("SETTINGS", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.settings_button:setTextSize(40);
    miniGame.settings_button:setSize(220, 75);
    miniGame.settings_button:setColor(0, 0, 0, 255);
    miniGame.settings_button:setBorderColor(255, 255, 255, 255);
    miniGame.settings_button:setTextColor(255, 255, 255, 255);
    miniGame.settings_button:setPosition(150, 570);
    
    miniGame.credits_button = Button.new("CREDITS", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.credits_button:setTextSize(40);
    miniGame.credits_button:setSize(220, 75);
    miniGame.credits_button:setColor(0, 0, 0, 255);
    miniGame.credits_button:setBorderColor(245, 245, 255, 255);
    miniGame.credits_button:setTextColor(245, 245, 255, 255);
    miniGame.credits_button:setPosition(400, 570);
    
    miniGame.exit_button = Button.new("QUIT", "assets/font/Mario-Kart-DS.ttf", 200, 200);
    miniGame.exit_button:setTextSize(40);
    miniGame.exit_button:setSize(220, 75);
    miniGame.exit_button:setColor(0, 0, 0, 255);
    miniGame.exit_button:setBorderColor(220, 0, 0, 255);
    miniGame.exit_button:setTextColor(220, 0, 0, 255);
    miniGame.exit_button:setPosition(650, 570);
    return;
end

function init(version)
    miniGame.image = Image.new("assets/sprites/game_logo.png");
    miniGame.sprite = Sprite.new(miniGame.image:getImage());
    miniGame.text = Text.new("ver: " .. version, "assets/font/Early_GameBoy.ttf");
    miniGame.sound = Sound.new("assets/sounds/random.ogg");
    miniGame.music = Music.new("assets/music/menu.ogg");
    miniGame.background = ScrollingBackground.new("assets/sprites/game_logo.png");
    --miniGame.background:setDirection(random_int(0, 359));
    buttons_init();
    miniGame.sprite:setPosition(400, 400);
    miniGame.text:setPosition(400, 10);
    --miniGame.music:play();
    miniGame.music:setReplayPoint(6);
    return true;
end

function pauseMenu()
    print("pause");
end

function update(window, deltaTime)
    if (miniGame.p1_pause or miniGame.p2_pause) then
        return;
    end
    miniGame.background:update(window);
    miniGame.sprite:update(window);
    miniGame.sprite:rotate(0.1);
    miniGame.text:update(window);
    --miniGame.music:update(window);
    miniGame.showdown_button:update(window);
    miniGame.freeplay_button:update(window);
    miniGame.controls_button:update(window);
    miniGame.settings_button:update(window);
    miniGame.credits_button:update(window);
    miniGame.exit_button:update(window);
    return;
end

function block_action()
    return false;
end

function on_P1_left()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action then
        return
    end
    miniGame.sprite:move(-1, 0);
    return;
end

function on_P1_right()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action then
        return
    end
    miniGame.sprite:move(1, 0);
    return;
end

function on_P1_up()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action then
        return
    end
    print("P1 up")
    return;
end

function on_P1_down()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action then
        return
    end
    print("P1 down")
    return;
end

function on_P1_1()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action then
        return
    end
    miniGame.sound:play();
    return;
end

function on_P1_2()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action then
        return
    end
    print("P1 action")
    return;
end

function on_P1_3()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action then
        return
    end
    print("P1 action")
    return;
end

function on_P1_start(is_minigame_running, pause)
    if miniGame.p2_pause
    or block_action then
        return
    end
    if (is_minigame_running) then
        if (not miniGame.p1_pause) then
            miniGame.p1_pause = true;
        else
            miniGame.p1_pause = false;
        end
    else
        miniGame.p1_leads = not miniGame.p1_leads;
    end
    return;
end

function on_P2_left()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action then
        return
    end
    print("P2 left")
    return;
end

function on_P2_right()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action then
        return
    end

    print("P2 right")
    return;
end

function on_P2_up()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action then
        return
    end

    print("P2 up")
    return;
end

function on_P2_down()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action then
        return
    end

    print("P2 down")
    return;
end

function on_P2_1()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action then
        return
    end

    print("P2 action")
    return;
end

function on_P2_2()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action then
        return
    end


    print("P2 action")
    return;
end

function on_P2_3()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action then
        return
    end


    print("P2 action")
    return;
end

function on_P2_start(is_minigame_running, pause)
    if miniGame.p1_pause 
    or block_action then
        return
    end

    if (is_minigame_running) then
        if (not miniGame.p2_pause) then
            miniGame.p2_pause = true;
        else
            miniGame.p2_pause = false;
        end
    else
        miniGame.p1_leads = not miniGame.p1_leads;
    end
    print("P2 start")
    return;
end
