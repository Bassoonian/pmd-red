#include "global.h"
#include "event_flag.h"
#include "memory.h"
#include "friend_area.h"

extern void sub_800226C(u8 r0, u8 r1, u32* r2, u8 u3);
extern void sub_800160C(struct UnkEventStruct *r0, u32 r1, u32 r2);
extern u8 sub_8002658(s16);

struct unkEventStruct
{
    // size: 0x4
    s16 unk0;
    u8 unk2; // Seems like friend area number
};

extern struct unkEventStruct gUnknown_80B71E4[58];

extern u8 gUnknown_2000A88[0x400];

s16 sub_8002694(u8 param_1)
{

    struct unkEventStruct *puVar2 = gUnknown_80B71E4;

    while (puVar2->unk0 != -1) {
        if (puVar2->unk2 == param_1) {
            return puVar2->unk0;
        }
        puVar2++;
    }

    return -1;
}

bool8 sub_80026CC(s16 r0)
{
    return GetFriendAreaStatus(sub_8002658(r0));
}

void sub_80026E8(s16 r0)
{
    UnlockFriendArea(sub_8002658(r0));
}

bool8 sub_8002700(void *r0)
{
    MemoryCopy8(r0, gUnknown_2000A88, 0x400);
    return 1;
}

bool8 sub_8002718(u8 *r0)
{
    struct UnkEventStruct temp;
    sub_800160C(&temp, 0, 0);
    MemoryCopy8(gUnknown_2000A88, r0, 0x400);
    if (temp.unk0[5] != temp.unk4[0])
        return 0;
    return 1;
}

void sub_8002758(u32 *r0)
{
    sub_800226C(0, 0x1, r0, 0x9);
}

u8 sub_800276C(void)
{
    return 0;
}

void nullsub_140(void)
{

}
