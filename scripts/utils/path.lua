--/
-- Quentin Duval 2024
-- Free Projects
-- GitHub: @Qua-9-9-1
-- Email:  quentduva@gmail.com
--\

local lfs = require("lfs")

local function get_absolute_path(relative_path)
    local base_path = lfs.currentdir()
    return base_path .. "/" .. relative_path
end

return {
    get_absolute_path = get_absolute_path
}
