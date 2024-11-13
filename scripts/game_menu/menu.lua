--/
-- Quentin Duval 2024
-- Free Projects
-- GitHub: @Qua-9-9-1
-- Email:  quentduva@gmail.com
--\

local WINDOW_WIDTH = 800
local WINDOW_HEIGHT = 600
local main_menu = require("scripts/game_menu/main_menu")
local controls = require("scripts/game_menu/controls")

local menu_location = {
    main_menu = 0,
    showdown = 1,
    freeplay = 2,
    controls = 3,
    settings = 4,
    credits = 5,
};

local miniGame = {
    background_image = nil,
    background = nil;
    music = nil;
    switch_player = nil;
    p1_pause = false;
    p2_pause = false;
    p1_leads = true;
    location = menu_location.main_menu;
};

function init(version)
    miniGame.background_image = Image.new("assets/sprites/game_menu.png");
    miniGame.background = ScrollingBackground.new(miniGame.background_image:getImage());
    miniGame.background:setScale(0.5, 0.5);
    miniGame.background:setDirection(math.random(0, 360));
    miniGame.background:setColor(math.random(150, 255), math.random(150, 255), math.random(150, 255), 255);
    miniGame.music = Music.new("assets/music/menu.ogg");
    miniGame.music:play();
    miniGame.music:setReplayPoint(6);
    main_menu.init(version);
    return true;
end

function pauseMenu()
    print("pause");
end

function update(window, deltaTime)
    if (miniGame.p1_pause or miniGame.p2_pause) then
        return;
    end
    miniGame.background:update();
    miniGame.background:draw(window);
    miniGame.music:update();
    if miniGame.location == menu_location.main_menu then
        main_menu.update(window);
    end
    return;
end

function block_action()
    return false;
end

function on_P1_left()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    if miniGame.location == menu_location.main_menu then
        main_menu.iter_button(false);
    end
    return;
end

function on_P1_right()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    if miniGame.location == menu_location.main_menu then
        main_menu.iter_button(true);
    end
    return;
end

function on_P1_up()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    if miniGame.location == menu_location.main_menu then
        main_menu.iter_button(false);
    end
    return;
end

function on_P1_down()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    if miniGame.location == menu_location.main_menu then
        main_menu.iter_button(true);
    end
    return;
end

function on_P1_1()
    if miniGame.p2_pause
    or not miniGame.p1_leads
    or block_action() then
        return
    end
    if miniGame.location == menu_location.main_menu then
        main_menu.select_button();
    end
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
    if miniGame.location == menu_location.main_menu then
        main_menu.iter_button(false);
    end
    return;
end

function on_P2_right()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action() then
        return
    end
    if miniGame.location == menu_location.main_menu then
        main_menu.iter_button(true);
    end
    return;
end

function on_P2_up()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action() then
        return
    end
    if miniGame.location == menu_location.main_menu then
        main_menu.iter_button(false);
    end
    return;
end

function on_P2_down()
    if miniGame.p1_pause
    or miniGame.p1_leads
    or block_action() then
        return
    end
    if miniGame.location == menu_location.main_menu then
        main_menu.iter_button(true);
    end
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
