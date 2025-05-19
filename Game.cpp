#include "Game.h"

namespace Game
{
    uint32_t __stdcall GetObjectPointer(uint64_t guid)
    {
        typedef uint32_t __fastcall func(uint64_t guid);
        func* function = (func*)Offsets::FUN_GET_OBJECT_POINTER;

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

    void Interact(uint32_t pointer, int autoloot, int fun_ptr)
    {
        FUN_ONRIGHTCLICK function = reinterpret_cast<FUN_ONRIGHTCLICK>(fun_ptr);
        function(pointer, autoloot);
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
}