#pragma once

#include <cstdint>

enum ObjectType
{
    NONE,
    ITEM,
    CONTAINER,
    UNIT,
    PLAYER,
    GAMEOBJECT,
    DYNAMICOBJECT,
    CORPSE
};

enum Offsets
{
    FUN_CUSTOM_INTERACT =       0x517405,
    FUN_OBJECT_POINTER =        0x464870,
    FUN_IS_IN_WORLD =           0xB4B424,
    FUN_LOAD_SCRIPT_FUNCTIONS = 0x490250,
    FUN_LUA_CFUNCTION =         0x6F3070,
    FUN_REGISTER_FUNCTION =     0x704120,
    FUN_RIGHT_CLICK_UNIT =      0x60BEA0,
    FUN_RIGHT_CLICK_OBJECT =    0x5F8660,
    FUN_SET_TARGET =            0x493540,
    LUA_ERROR =                 0x6F4940,
    LUA_ISNUMBER =              0x6F34D0,
    LUA_TONUMBER =              0x6F3620,
    VISIBLE_OBJECTS =           0xB41414,
};

typedef int(__fastcall* LUA_CFUNCTION)(void* L);
typedef void(__thiscall* FUN_ONRIGHTCLICK)(uint32_t pointer, int autoloot);
typedef void(__fastcall* FrameScript_RegisterFunction)(const char*, uintptr_t);
typedef void(__cdecl* lua_error)(void*, const char*);
typedef bool(__fastcall* lua_isnumber)(void*, int);
typedef double(__fastcall* lua_tonumber)(void*, int);

typedef struct
{
    float y;
    float x;
    float z;
} C3Vector;

namespace Game
{
    auto const RegisterFunction = (FrameScript_RegisterFunction)Offsets::FUN_REGISTER_FUNCTION;

    uint32_t __stdcall GetObjectPointer(uint64_t guid);

    C3Vector GetObjectPosition(uint32_t pointer);

    int GetUnitHealth(uint32_t unit);

    C3Vector GetUnitPosition(uint32_t unit);

    void Interact(uint32_t pointer, int autoloot, int fun_ptr);

    bool IsUnitLootable(uint32_t unit);
    bool IsUnitSkinnable(uint32_t unit);

    void SetTarget(uint64_t guid);

    inline bool IsInWorld() { return *(char*)Offsets::FUN_IS_IN_WORLD; }
}

namespace Lua
{
    auto const PrintError = (lua_error)Offsets::LUA_ERROR;
    auto const IsNumber = (lua_isnumber)Offsets::LUA_ISNUMBER;
    auto const ToNumber = (lua_tonumber)Offsets::LUA_TONUMBER;
}