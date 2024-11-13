local freeplay = {}

local game_list = {}

local objects = {
    cursor_sound = nil;
    buttons = {};
    selected_button = 1;
}

function freeplay.init()
    game_list = {
        new.Text("thumb", "assets/font/Early_GameBoy.ttf");
        new.Text("judge", "assets/font/Early_GameBoy.ttf");
    }
    for i = 1, #game_list do
        game_list[i]:setColor(255, 255, 255, 255);
        game_list[i]:setScale(0.5, 0.5);
    end
    game_list[1]:setPosition(250, 150);
    game_list[2]:setPosition(500, 150);
end

function freeplay.update(window, deltaTime)
    for i = 1, #game_list do
        game_list[i]:draw(window);
    end
end

