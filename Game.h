#pragma once

#include "Offsets.h"

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
    auto const RegisterFunction = (FrameScript_RegisterFunction)Offsets::FUN_REGISTER_LUA_FUNCTION;

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