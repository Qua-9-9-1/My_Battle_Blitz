local game = {}

local SPRITE_WIDTH = 164
local SPRITE_HEIGHT = 138

local miniGame = {
    background = nil,
    image = nil,
    sprite = nil,
    music = nil,
    Text = nil,
    p1_state = 0,
    p1_last_state = 0,
    p2_state = 0,
    p2_last_state = 0,
    winner = 0,
    game_over = false

}

function game.init()
    miniGame.background = SolidColorBackground.new(0, 255, 0, 255);
    miniGame.image = Image.new("assets/sprites/thumb_wrestling.png");
    miniGame.sprite = Sprite.new(miniGame.image:getImage());
    miniGame.sprite:setSmooth(false);
    miniGame.sprite:setTextureRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT);
    miniGame.sprite:setScale(4.1, 4.1);
    miniGame.sprite:setPosition(1750, 600);
    miniGame.music = Music.new("assets/music/sticks.ogg");
    miniGame.music:play();
    return true;
end

function game.update(deltaTime)
    if miniGame.game_over then
        miniGame.music:stop();
        return;
    end
    if miniGame.p1_state == 0 and miniGame.p2_state == 0 then
        miniGame.sprite:setTextureRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT);
    elseif miniGame.p1_state == 1 and miniGame.p2_state == 0 then
        miniGame.sprite:setTextureRect(SPRITE_WIDTH, 0, SPRITE_WIDTH * 2, SPRITE_HEIGHT);
    elseif miniGame.p1_state == 2 and miniGame.p2_state == 0 then
        miniGame.sprite:setTextureRect(SPRITE_WIDTH, SPRITE_HEIGHT, SPRITE_WIDTH * 2, SPRITE_HEIGHT);
    elseif miniGame.p1_state == 0 and miniGame.p2_state == 1 then
        miniGame.sprite:setTextureRect(SPRITE_WIDTH * 3, 0, SPRITE_WIDTH * 4, SPRITE_HEIGHT * 2);
    elseif miniGame.p1_state == 0 and miniGame.p2_state == 2 then
        miniGame.sprite:setTextureRect(SPRITE_WIDTH * 2, SPRITE_HEIGHT, SPRITE_WIDTH * 3, SPRITE_HEIGHT * 2);
    elseif miniGame.p1_state == 2 and miniGame.p2_state == 1 then
        miniGame.sprite:setTextureRect(SPRITE_WIDTH * 3, SPRITE_HEIGHT, SPRITE_WIDTH * 4, SPRITE_HEIGHT * 2);
    elseif miniGame.p1_state == 1 and miniGame.p2_state == 2 then
        miniGame.sprite:setTextureRect(SPRITE_WIDTH * 4, SPRITE_HEIGHT, SPRITE_WIDTH * 5, SPRITE_HEIGHT * 2);
    elseif miniGame.p1_state == 2 and miniGame.p2_state == 2 then
        miniGame.sprite:setTextureRect(0, SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT * 2);
    elseif miniGame.winner ~= 0 then
        if miniGame.winner == 1 then
            miniGame.sprite:setTextureRect(SPRITE_WIDTH * 4, 0, SPRITE_WIDTH * 5, SPRITE_HEIGHT);
        else
            miniGame.sprite:setTextureRect(SPRITE_WIDTH * 2, 0, SPRITE_WIDTH * 3, SPRITE_HEIGHT);
        end
        miniGame.game_over = true;
    end
    miniGame.p1_last_state = miniGame.p1_state;
    miniGame.p1_state = 0;
    miniGame.p2_last_state = miniGame.p2_state;
    miniGame.p2_state = 0;
end

function game.draw(window)
    miniGame.background:draw(window);
    miniGame.sprite:draw(window);
    return;
end

function game.P1_press()
    if miniGame.p2_last_state == 1 then
        miniGame.winner = 1;
    end
    miniGame.p1_state = 1;
    return;
end

function game.P1_feint()
    miniGame.p1_state = 2;
    return;
end

function game.P2_press()
    if miniGame.p1_last_state == 1 then
        miniGame.winner = 2;
    end
    miniGame.p2_state = 1;
    return;
end

function game.P2_feint()
    miniGame.p2_state = 2;
    return;
end

return game;