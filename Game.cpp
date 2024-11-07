#include "Game.h"

LUA_CFUNCTION p_lua_gettop = reinterpret_cast<LUA_CFUNCTION>(Offsets::FUN_LUA_CFUNCTION);
LUA_TOSTRING p_lua_tostring = reinterpret_cast<LUA_TOSTRING>(Offsets::FUN_LUA_TOSTRING);

namespace Game
{
    uint32_t __stdcall GetObjectPointer(uint64_t guid)
    {
        typedef uint32_t __fastcall func(uint64_t guid);
        func* function = (func*)Offsets::FUN_OBJECT_POINTER;

        return function(guid);
    }

    C3Vector GetObjectPosition(uint32_t pointer)
    {
        pointer = *reinterpret_cast<uint32_t*>(pointer + 0x110);
        return
        {
            *reinterpret_cast<float*>(pointer + 0x24),
            *reinterpret_cast<float*>(pointer + 0x28),
            *reinterpret_cast<float*>(pointer + 0x2C),
        };
    }

    int GetUnitHealth(uint32_t unit)
    {
        return *reinterpret_cast<int*>(*reinterpret_cast<uint32_t*>(unit + 0x8) + 0x58);
    }

    C3Vector GetUnitPosition(uint32_t unit)
    {
        return
        {
            *reinterpret_cast<float*>(unit + 0x09B8),
            *reinterpret_cast<float*>(unit + 0x09BC),
            *reinterpret_cast<float*>(unit + 0x09C0),
        };
    }

    void Interact(int pointer, int fun_ptr)
    {
        FUN_INTERACT* function = (FUN_INTERACT*)fun_ptr;
        function(pointer, 1);

        Game::LootAll();
    }

    bool IsUnitLootable(uint32_t unit)
    {
        int flags = *reinterpret_cast<int*>(*reinterpret_cast<uint32_t*>(unit + 0x8) + 0x23C);
        return (flags & 1) != 0;
    }

    bool IsUnitSkinnable(uint32_t unit)
    {
        int flags = *reinterpret_cast<int*>(*reinterpret_cast<uint32_t*>(unit + 0x8) + 0xB8);
        int flag = 0x4000000;
        return (flags & flag) == flag;
    }

    void SetTarget(uint64_t guid)
    {
        typedef void __stdcall func(uint64_t guid);
        func* function = (func*)Offsets::FUN_SET_TARGET;

        function(guid);
    }

    void LootAll()
    {
        typedef void __stdcall func();
        func* function = (func*)Offsets::FUN_AUTOLOOT;

        function();
    }
}

namespace Lua
{
    const char* ToString(void* L, int index)
    {
        return p_lua_tostring(L, index);
    }

    int GetTop(void* L)
    {
        return p_lua_gettop(L);
    }
}