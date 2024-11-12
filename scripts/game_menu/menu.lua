--/
-- Quentin Duval 2024
-- Free Projects
-- GitHub: @Qua-9-9-1
-- Email:  quentduva@gmail.com
--\

local WINDOW_WIDTH = 800
local WINDOW_HEIGHT = 600
local random_angle = math.random(0, 360);
local random_red = math.random(150, 255);
local random_green = math.random(150, 255);
local random_blue = math.random(150, 255);

-- local random = require("random");

local miniGame = {
    image = nil,
    sound = nil;
    cursor_sound = nil;
    text = nil;
    background = nil;
    music = nil;
    cursor = nil;
    select = nil;
    switch_player = nil;
    buttons = {};
    selectedIndex = 1;
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
    miniGame.buttons = {
        Button.new("SHOWDOWN", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("FREEPLAY", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("CONTROLS", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("SETTINGS", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("CREDITS", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("QUIT", "assets/font/Mario-Kart-DS.ttf", 200, 200)
    }
    for i = 1, 6 do
        if i < 4 then
            miniGame.buttons[i]:setTextSize(70)
            miniGame.buttons[i]:setSize(480, 100)
            miniGame.buttons[i]:setColor(0, 0, 0, 255)
        else
            miniGame.buttons[i]:setTextSize(40)
            miniGame.buttons[i]:setSize(220, 75)
            miniGame.buttons[i]:setColor(0, 0, 0, 255)
        end
        miniGame.buttons[i]:setBorderColor(255, 255, 255, 255)
        miniGame.buttons[i]:setTextColor(255, 255, 255, 255)
    end
    miniGame.buttons[1]:setPosition(400, 130)
    miniGame.buttons[2]:setPosition(400, 280)
    miniGame.buttons[3]:setPosition(400, 430)
    miniGame.buttons[4]:setPosition(150, 570)
    miniGame.buttons[5]:setPosition(400, 570)
    miniGame.buttons[6]:setBorderColor(220, 0, 0, 255)
    miniGame.buttons[6]:setTextColor(220, 0, 0, 255)
    miniGame.buttons[6]:setPosition(650, 570)
end

function init(version)
    miniGame.image = Image.new("assets/sprites/game_menu.png");
    miniGame.text = Text.new("ver: " .. version, "assets/font/Early_GameBoy.ttf");
    miniGame.sound = Sound.new("assets/sounds/random.ogg");
    miniGame.cursor_sound = Sound.new("assets/sounds/move_cursor.wav");
    miniGame.music = Music.new("assets/music/menu.ogg");
    miniGame.background = ScrollingBackground.new(miniGame.image:getImage());
    miniGame.background:setScale(0.5, 0.5);
    miniGame.background:setDirection(random_angle);
    miniGame.background:setColor(random_red, random_green, random_blue, 255);
    buttons_init();
    miniGame.text:setPosition(620, 25);
    miniGame.text:setBorderThickness(2);
    miniGame.music:play();
    miniGame.music:setReplayPoint(6);
    return true;
end

function pauseMenu()
    print("pause");
end

function draw_buttons(window)
    for i = 1, 6 do
        miniGame.buttons[i]:draw(window);
    end
    miniGame.buttons[miniGame.selectedIndex]:setBorderColor(255, 255, 50, 255);
    miniGame.buttons[miniGame.selectedIndex]:setTextColor(255, 255, 50, 255);
end

function update(window, deltaTime)
    if (miniGame.p1_pause or miniGame.p2_pause) then
        return;
    end
    miniGame.background:update(window);
    miniGame.background:draw(window);
    miniGame.text:draw(window);
    draw_buttons(window);
    miniGame.music:update(window);
    return;
end

function block_action()
    return false;
end

function iter_button(next)
    miniGame.cursor_sound:play();
    if miniGame.selectedIndex == 6 then
        miniGame.buttons[miniGame.selectedIndex]:setBorderColor(255, 0, 0, 255);
        miniGame.buttons[miniGame.selectedIndex]:setTextColor(255, 0, 0, 255);
    else     
        miniGame.buttons[miniGame.selectedIndex]:setBorderColor(255, 255, 255, 255);
        miniGame.buttons[miniGame.selectedIndex]:setTextColor(255, 255, 255, 255);
    end
    if next then
        miniGame.selectedIndex = miniGame.selectedIndex + 1
        if miniGame.selectedIndex == 7 then
            miniGame.selectedIndex = 1
        end
    else
        miniGame.selectedIndex = miniGame.selectedIndex - 1
        if miniGame.selectedIndex == 0 then
            miniGame.selectedIndex = 6
        end
    end
end

function on_P1_left()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    iter_button(false);
    return;
end

function on_P1_right()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    iter_button(true);
    return;
end

function on_P1_up()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    iter_button(false);
    return;
end

function on_P1_down()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    iter_button(true);
    return;
end

function on_P1_1()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    miniGame.sound:play();
    return;
end

function on_P1_2()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    print("P1 action")
    return;
end

function on_P1_3()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    print("P1 action")
    return;
end

function on_P1_start(is_minigame_running, pause)
    if miniGame.p2_pause
    or block_action() then
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
    or block_action() then
        return
    end
    iter_button(false);
    return;
end

function on_P2_right()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action() then
        return
    end
    iter_button(true);
    return;
end

function on_P2_up()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action() then
        return
    end
    iter_button(false);
    return;
end

function on_P2_down()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action() then
        return
    end
    iter_button(true);
    return;
end

function on_P2_1()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action() then
        return
    end

    print("P2 action")
    return;
end

function on_P2_2()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action() then
        return
    end


    print("P2 action")
    return;
end

function on_P2_3()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action() then
        return
    end

    print("P2 action")
    return;
end

function on_P2_start(is_minigame_running, pause)
    if miniGame.p1_pause 
    or block_action() then
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
