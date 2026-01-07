
local game = require("scripts/minigames/thumb_wrestling/game")

function init()
    gameEngine:setOneTimeButtons(false);
    game.init();
    return true;
end

function update(window, deltaTime)
    game.update(deltaTime);
    return;
end

function draw(window)
    game.draw(window);
    return;
end

function on_P1_left()
    return;
end

function on_P1_right()
    return;
end

function on_P1_up()
    return;
end

function on_P1_down()
    return;
end

function on_P1_1()
    game.P1_press();
    return;
end

function on_P1_2()
    game.P1_feint();
    return;
end

function on_P1_3()
    gameEngine:stopMiniGame();
    return;
end

function on_P1_start()
    return;
end

function on_P2_left()
    return;
end

function on_P2_right()
    return;
end

function on_P2_up()
    return;
end

function on_P2_down()
    return;
end

function on_P2_1()
    game.P2_press();
    return;
end

function on_P2_2()
    game.P2_feint();
    return;
end

function on_P2_3()
    return;
end

function on_P2_start()
    return;
end