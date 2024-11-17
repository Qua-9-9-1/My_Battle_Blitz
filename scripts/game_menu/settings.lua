local settings = {}

local options = {
    full_screen = false;
    music_volume = 100;
    sound_volume = 100;
    graphics = 1;
    language = 1;
    beginner_mode = false;
}

local options_texts = {
    screen = nil,
    screen_option = nil,
    music = nil,
    music_option = nil,
    sound = nil,
    sound_option = nil,
    graphics = nil,
    graphics_option = nil,
    language = nil,
    language_option = nil,
    beginner = nil,
    beginner_option = nil
}

local objects = {
    cursor_sound = nil;
    buttons = {};
    selected_option = 1;
    inited_options = false;
}

function settings.init()
    options_texts = {
        Text.new("Screen display", "assets/font/Early_GameBoy.ttf");
        Text.new("Windowed", "assets/font/Early_GameBoy.ttf");
        Text.new("Music volume", "assets/font/Early_GameBoy.ttf");
        Text.new("100", "assets/font/Early_GameBoy.ttf");
        Text.new("Sound volume", "assets/font/Early_GameBoy.ttf");
        Text.new("100", "assets/font/Early_GameBoy.ttf");
        Text.new("Graphics", "assets/font/Early_GameBoy.ttf");
        Text.new("High", "assets/font/Early_GameBoy.ttf");
        Text.new("Language", "assets/font/Early_GameBoy.ttf");
        Text.new("EN", "assets/font/Early_GameBoy.ttf");
        Text.new("Beginner mode", "assets/font/Early_GameBoy.ttf");
        Text.new("Off", "assets/font/Early_GameBoy.ttf");
    }
    for i = 1, #options_texts do
        options_texts[i]:setColor(255, 255, 255, 255);
        options_texts[i]:setScale(0.5, 0.5);
    end
    options_texts[1]:setPosition(250, 150);
    options_texts[2]:setPosition(500, 150);
    options_texts[3]:setPosition(250, 200);
    options_texts[4]:setPosition(500, 200);
    options_texts[5]:setPosition(250, 250);
    options_texts[6]:setPosition(500, 250);
    options_texts[7]:setPosition(250, 300);
    options_texts[8]:setPosition(500, 300);
    options_texts[9]:setPosition(250, 350);
    options_texts[10]:setPosition(500, 350);
    options_texts[11]:setPosition(250, 400);
    options_texts[12]:setPosition(500, 400);
    options_texts[objects.selected_option]:setColor(255, 255, 50, 255);
    options_texts[objects.selected_option + 1]:setColor(255, 255, 50, 255);
    objects.cursor_sound = Sound.new("assets/sounds/move_cursor.wav");
end

function set_settings(game_settings)
    if (options.full_screen ~= game_settings.fullScreen) then
        game_settings.fullScreen = options.full_screen;
        if (game_settings.fullScreen) then
            options_texts[2]:setString("Full screen");
        else
            options_texts[2]:setString("Windowed");
        end
    end
    if (options.music_volume ~= game_settings.musicVolume) then
        game_settings.musicVolume = options.music_volume;
        options_texts[4]:setString(tostring(game_settings.musicVolume));
    end
    if (options.sound_volume ~= game_settings.soundVolume) then
        game_settings.soundVolume = options.sound_volume;
        options_texts[6]:setString(tostring(game_settings.soundVolume));
    end
    if (options.graphics ~= game_settings.graphics) then
        game_settings.graphics = options.graphics;
        if (game_settings.graphics == 1) then
            options_texts[8]:setString("Low");
        elseif (game_settings.graphics == 2) then
            options_texts[8]:setString("Medium");
        else
            options_texts[8]:setString("High");
        end
    end
    if (options.language ~= game_settings.language) then
        game_settings.language = options.language;
        if (game_settings.language == 1) then
            options_texts[10]:setString("EN");
        else
            options_texts[10]:setString("FR");
        end
    end
    if (options.beginner_mode ~= game_settings.beginnerMode) then
        game_settings.beginnerMode = options.beginner_mode;
        if (game_settings.beginnerMode) then
            options_texts[12]:setString("On");
        else
            options_texts[12]:setString("Off");
        end
    end
end

function settings.update(window, deltaTime, game_settings)
    if (objects.inited_options == false) then
        options.full_screen = game_settings.fullScreen;
        options.music_volume = game_settings.musicVolume;
        options.sound_volume = game_settings.soundVolume;
        options.graphics = game_settings.graphics;
        options.language = game_settings.language;
        options.beginner_mode = game_settings.beginnerMode;
        objects.inited_options = true;
    end
    set_settings(game_settings);
    for i = 1, #options_texts do
        options_texts[i]:draw(window);
    end
end

function settings.iter_option(next)
    options_texts[objects.selected_option]:setColor(255, 255, 255, 255);
    options_texts[objects.selected_option + 1]:setColor(255, 255, 255, 255);
    if next then
        objects.selected_option = objects.selected_option + 2;
        if objects.selected_option >= #options_texts then
            objects.selected_option = 1;
        end
    else
        objects.selected_option = objects.selected_option - 2;
        if objects.selected_option <= 0 then
            objects.selected_option = #options_texts - 1;
        end
    end
    options_texts[objects.selected_option]:setColor(255, 255, 50, 255);
    options_texts[objects.selected_option + 1]:setColor(255, 255, 50, 255);
end

function settings.change_option(next)
    if objects.selected_option == 1 then
        options.full_screen = not options.full_screen;
    elseif objects.selected_option == 3 then
        if next then
            options.music_volume = options.music_volume + 10;
            if options.music_volume > 100 then
                options.music_volume = 100;
            end
        else
            options.music_volume = options.music_volume - 10;
            if options.music_volume < 0 then
                options.music_volume = 0;
            end
        end
    elseif objects.selected_option == 5 then
        if next then
            options.sound_volume = options.sound_volume + 10;
            if options.sound_volume > 100 then
                options.sound_volume = 100;
            end
        else
            options.sound_volume = options.sound_volume - 10;
            if options.sound_volume < 0 then
                options.sound_volume = 0;
            end
        end
    elseif objects.selected_option == 7 then
        if next then
            options.graphics = options.graphics + 1;
        else
            options.graphics = options.graphics - 1;
        end
        if options.graphics > 3 then
            options.graphics = 1;
        end
        print(options.graphics);
    elseif objects.selected_option == 9 then
        if next then
            options.language = options.language + 1;
        else
            options.language = options.language - 1;
        end
        if options.language > 2 then
            options.language = 1;
        end
    elseif objects.selected_option == 11 then
        options.beginner_mode = not options.beginner_mode;
        gameEngine:toggleFullScreen();
    end
end

function settings.press(miniGame)
    miniGame.location = 0;
end
        
return settings