#pragma once

enum Offsets
{
    // Custom functions
    FUN_CUSTOM_INTERACT         = 0x517405,
    // Game functions
    FUN_GET_OBJECT_POINTER      = 0x464870,
    FUN_IS_IN_WORLD             = 0xB4B424,
    FUN_LOAD_SCRIPT_FUNCTIONS   = 0x490250,
    FUN_REGISTER_LUA_FUNCTION   = 0x704120,
    FUN_RIGHT_CLICK_UNIT        = 0x60BEA0,
    FUN_RIGHT_CLICK_OBJECT      = 0x5F8660,
    FUN_SET_TARGET              = 0x493540,
    // Lua API functions
    LUA_ERROR                   = 0x6F4940,
    LUA_ISNUMBER                = 0x6F34D0,
    LUA_TONUMBER                = 0x6F3620,
    // Misc
    VISIBLE_OBJECTS             = 0xB41414,
};