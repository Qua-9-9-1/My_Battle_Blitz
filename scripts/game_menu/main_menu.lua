local main_menu = {}

local objects = {
    select_sound = nil;
    cursor_sound = nil;
    version_text = nil;
    buttons = {};
    selected_button = 1;
    quit = false;
}

function buttons_init()
    objects.buttons = {
        Button.new("SHOWDOWN", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("FREEPLAY", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("CONTROLS", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("SETTINGS", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("CREDITS", "assets/font/Mario-Kart-DS.ttf", 200, 200),
        Button.new("QUIT", "assets/font/Mario-Kart-DS.ttf", 200, 200)
    }
    for i = 1, 6 do
        if i < 4 then
            objects.buttons[i]:setTextSize(70)
            objects.buttons[i]:setSize(480, 100)
            objects.buttons[i]:setColor(0, 0, 0, 255)
        else
            objects.buttons[i]:setTextSize(40)
            objects.buttons[i]:setSize(220, 75)
            objects.buttons[i]:setColor(0, 0, 0, 255)
        end
        objects.buttons[i]:setBorderColor(255, 255, 255, 255)
        objects.buttons[i]:setTextColor(255, 255, 255, 255)
    end
    objects.buttons[1]:setPosition(400, 130)
    objects.buttons[2]:setPosition(400, 280)
    objects.buttons[3]:setPosition(400, 430)
    objects.buttons[4]:setPosition(150, 570)
    objects.buttons[5]:setPosition(400, 570)
    objects.buttons[6]:setBorderColor(220, 0, 0, 255)
    objects.buttons[6]:setTextColor(220, 0, 0, 255)
    objects.buttons[6]:setPosition(650, 570)
end

function main_menu.init(version)
    objects.select_sound = Sound.new("assets/sounds/random.ogg");
    objects.cursor_sound = Sound.new("assets/sounds/move_cursor.wav");
    buttons_init();
    objects.version_text = Text.new("ver: " .. version, "assets/font/Early_GameBoy.ttf");
    objects.version_text:setPosition(620, 25);
    objects.version_text:setBorderThickness(2);
end

function draw_buttons(window)
    for i = 1, 6 do
        objects.buttons[i]:draw(window);
    end
    objects.buttons[objects.selected_button]:setBorderColor(255, 255, 50, 255);
    objects.buttons[objects.selected_button]:setTextColor(255, 255, 50, 255);
end

function main_menu.update(window)
    objects.version_text:draw(window);
    draw_buttons(window);
    if objects.quit then
        window:close();
    end
end

function main_menu.iter_button(next)
    objects.cursor_sound:play();
    if objects.selected_button == 6 then
        objects.buttons[objects.selected_button]:setBorderColor(255, 0, 0, 255);
        objects.buttons[objects.selected_button]:setTextColor(255, 0, 0, 255);
    else     
        objects.buttons[objects.selected_button]:setBorderColor(255, 255, 255, 255);
        objects.buttons[objects.selected_button]:setTextColor(255, 255, 255, 255);
    end
    if next then
        objects.selected_button = objects.selected_button + 1        
        if objects.selected_button == #objects.buttons + 1 then
            objects.selected_button = 1
        end
    else
        objects.selected_button = objects.selected_button - 1
        if objects.selected_button == 0 then
            objects.selected_button = #objects.buttons 
        end
    end
end

function main_menu.select_button()
    objects.select_sound:play();
    if objects.selected_button == 1 then
        print("showdown");
    elseif objects.selected_button == 2 then
        print("freeplay");
    elseif objects.selected_button == 3 then
        print("controls");
    elseif objects.selected_button == 4 then
        print("settings");
    elseif objects.selected_button == 5 then
        print("credits");
    elseif objects.selected_button == 6 then
        objects.quit = true;
    end
end
        
return main_menu