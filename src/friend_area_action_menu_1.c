#include "global.h"
#include "text.h"
#include "input.h"
#include "menu.h"
#include "item.h"
#include "team_inventory.h"
#include "pokemon.h"
#include "friend_area_action_menu.h"

extern struct unkStruct_203B2BC *gUnknown_203B2BC;
extern struct TeamInventory *gTeamInventory_203B460;

extern u32 sub_801B410();
extern void sub_801B450();
extern u32 sub_801EF38(u8 r0);
extern void sub_801F214();

extern void SetFriendAreaActionMenuState(u32);
extern u8 sub_8012FD8(u32 *r0);
extern void sub_8013114(u32 *, s32 *);
extern void PlaySound(u32);
extern void nullsub_104();
extern void sub_801A928();
extern void sub_8099690(u32);
extern u32 sub_801A8AC();
extern u32 sub_801A6E8(u32);

extern s32 sub_80144A4(s32 *);
extern void sub_8027EB8();
extern void sub_808D31C(struct PokemonStruct *);
extern u8 sub_80023E4(u32);
extern struct PokemonStruct *sub_808D3F8(void);
extern struct PokemonStruct *sub_808D3BC(void);
extern u32 sub_801F890(void);
extern void sub_801F8D0(void);
extern u8 gUnknown_80DD958[];
extern void xxx_format_and_draw(u32, u32, u8 *, ...);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u8 gUnknown_202DE58[];
extern u32 sub_801F194(void);

u32 sub_8027E18(struct PokemonStruct *);
u8 sub_8027E4C(struct PokemonStruct *r0);

extern u32 sub_801BF48(void);
extern void sub_801BF98(void);
extern u32 sub_80244E4(void);
extern void sub_802453C(void);

extern u32 sub_8023A94(u32);
extern bool8 sub_808D750(s16 index_);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern void sub_808ED00();
extern s16 sub_8023B44(void);
extern void sub_8023C60(void);

void sub_80277FC(void)
{
  struct PokemonStruct *iVar4;

  switch(sub_8023A94(1)) {
      case 0:
      case 1:
        break;
      case 3:
        gUnknown_203B2BC->targetPoke = sub_8023B44();
        iVar4 = &gRecruitedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
        gUnknown_203B2BC->unk18 = iVar4;
        gUnknown_203B2BC->unk1C = iVar4->isLeader;
        PeekPokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->unk14);
        SetFriendAreaActionMenuState(3);
        break;
      case 4:
        gUnknown_203B2BC->targetPoke = sub_8023B44();
        iVar4 = &gRecruitedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
        gUnknown_203B2BC->unk18 = iVar4;
        gUnknown_203B2BC->unk1C = iVar4->isLeader;
        PeekPokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->unk14);
        SetFriendAreaActionMenuState(4);
        break;
      case 2:
        sub_8023C60();
        SetFriendAreaActionMenuState(0x11);
        break;
  }
}

void sub_80278B4(void)
{
  struct PokemonStruct *playerStruct;
  struct PokemonStruct *puVar3;
  struct PokemonStruct *iVar4;
  int local_c;

  local_c = 0;
  sub_8023A94(0);
  if ((sub_8012FD8(&gUnknown_203B2BC->unk7C) == '\0') && (sub_8013114(&gUnknown_203B2BC->unk7C,&local_c), local_c != 1)) {
    gUnknown_203B2BC->unk70 = local_c;
  }
  switch(local_c) {
      case 6:
        if (sub_808D750(gUnknown_203B2BC->targetPoke) != '\0') {
#ifdef NONMATCHING
            puVar3 = &gRecruiedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
#else
        register size_t offset asm("r1") = offsetof(struct unkStruct_203B45C, pokemon[gUnknown_203B2BC->targetPoke]);
        struct PokemonStruct* p = gRecruitedPokemonRef->pokemon;
        size_t addr = offset + (size_t)p;
        puVar3 = (struct PokemonStruct*)addr;
#endif
          puVar3->unk0 |= 2;
          nullsub_104();
        }
        sub_808ED00();
        SetFriendAreaActionMenuState(2);
        break;
      case 7:
        gUnknown_203B2BC->unk18->unk0 &= 0xfffd;
        nullsub_104();
        sub_808ED00();
        SetFriendAreaActionMenuState(2);
        break;
      case 8:
        iVar4 = &gRecruitedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
        playerStruct = GetPlayerPokemonStruct();
        if (!iVar4->isLeader) {
          playerStruct->isLeader = FALSE;
          iVar4->isLeader = TRUE;
          nullsub_104();
        }
        sub_808ED00();
        SetFriendAreaActionMenuState(2);
        break;
      case 9:
        SetFriendAreaActionMenuState(8);
        break;
      case 0xc:
        SetFriendAreaActionMenuState(0xe);
        break;
      case 10:
        SetFriendAreaActionMenuState(10);
        break;
      case 0xb:
        PlaySound(0x14d);
        if (gUnknown_203B2BC->unk14.itemIndex != ITEM_ID_NOTHING) {
          AddHeldItemToInventory(&gUnknown_203B2BC->unk14);
        }
        FillInventoryGaps();
        gUnknown_203B2BC->unk14.itemIndex = 0;
        gUnknown_203B2BC->unk14.numItems = 0;
        GivePokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->unk14);
        nullsub_104();
        SetFriendAreaActionMenuState(2);
        break;
      case 4:
        SetFriendAreaActionMenuState(4);
        break;
      case 5:
        SetFriendAreaActionMenuState(5);
        break;
      case 1:
        SetFriendAreaActionMenuState(2);
        break;
  }
}

void sub_8027A40(void)
{
    switch(sub_80244E4())
    {
        case 2:
        case 3:
            sub_802453C();
            SetFriendAreaActionMenuState(2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8027A5C(void)
{
    switch(sub_801BF48())
    {
        case 2:
        case 3:
            sub_801BF98();
            SetFriendAreaActionMenuState(2);
            break;
        case 0:
        case 1:
            break;
    }
}

static inline bool8 sub_8027A78_sub(void) {
    if (gUnknown_203B2BC->unk18->unk4.dungeonIndex == 0x44 || gUnknown_203B2BC->unk18->unk4.dungeonIndex == 0x45)
        return TRUE;
    else
        return FALSE;
}

void sub_8027A78(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 1:
            case 3:
                SetFriendAreaActionMenuState(2);
                break;
            case 2:
                if (sub_8027A78_sub())
                    SetFriendAreaActionMenuState(9);
                else
                {
                    sub_8027EB8();
                    sub_808D31C(gUnknown_203B2BC->unk18);
                }
                break;
        }
    }
}

void sub_8027AE4(void)
{
  s32 local_8;

  if (sub_80144A4(&local_8) == 0) {
      switch(local_8)
      {
        case 1:
        case 3:
            SetFriendAreaActionMenuState(2);
            break;
        case 2:
            sub_8027EB8();
            sub_808D31C(gUnknown_203B2BC->unk18);
            break;
    }
  }
}

void sub_8027B28(void)
{
  switch(sub_801A6E8(1))
  {
    case 3:
        gUnknown_203B2BC->itemIndex = sub_801A8AC();
        gUnknown_203B2BC->itemToGive.itemIndex = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->itemIndex].itemIndex;
        gUnknown_203B2BC->itemToGive.numItems = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->itemIndex].numItems;
        SetFriendAreaActionMenuState(0xc);
        break;
    case 4:
        gUnknown_203B2BC->itemIndex = sub_801A8AC();
        gUnknown_203B2BC->itemToGive.itemIndex = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->itemIndex].itemIndex;
        gUnknown_203B2BC->itemToGive.numItems = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->itemIndex].numItems;
        sub_8099690(0);
        SetFriendAreaActionMenuState(0xd);
        break;
    case 2:
        sub_801A928();
        SetFriendAreaActionMenuState(2);
        break;
    case 0:
    case 1:
        break;
  }
}

void sub_8027BD8(void)
{
  s32 menuAction;

  menuAction = 0;
  sub_801A6E8(0);
  if ((sub_8012FD8(&gUnknown_203B2BC->unk7C) == 0) && (sub_8013114(&gUnknown_203B2BC->unk7C,&menuAction), menuAction != 1)) {
    gUnknown_203B2BC->unk74 = menuAction;
  }
  switch(menuAction)
  {
    case 10:
        PlaySound(0x14d);
        ShiftItemsDownFrom(gUnknown_203B2BC->itemIndex);
        FillInventoryGaps();
        if (gUnknown_203B2BC->unk14.itemIndex != 0) {
            AddHeldItemToInventory(&gUnknown_203B2BC->unk14);
        }
        GivePokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->itemToGive);
        sub_801A928();
        nullsub_104();
        SetFriendAreaActionMenuState(2);
        break;
    case 4:
        sub_8099690(0);
        SetFriendAreaActionMenuState(0xd);
        break;
    case 1:
        SetFriendAreaActionMenuState(0xb);
        break;
  }
}

void sub_8027C84()
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            SetFriendAreaActionMenuState(0xB);
        case 0:
        case 1:
            break;
    }
}

void sub_8027CA0(void)
{
    switch(sub_801EF38(1))
    {
        case 3:
        case 4:
            gUnknown_203B2BC->unk20 = sub_801F194();
            gUnknown_203B2BC->unk24 = gUnknown_203B2BC->unk28[gUnknown_203B2BC->unk20].moveID;
            SetFriendAreaActionMenuState(0x10);
            break;
        case 2:
            sub_801F214();
            SetFriendAreaActionMenuState(0x2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8027D00(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            SetFriendAreaActionMenuState(0xF);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8027D1C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendAreaActionMenuState(gUnknown_203B2BC->unk4);
    }
}

void sub_8027D40(u32 r0, struct HeldItem *heldItem)
{

    struct ItemSlot slot;
    struct unkStruct_8090F58 a3;

    sub_8008C54(r0);
    sub_80073B8(r0);
    HeldItemToSlot(&slot, heldItem);
    a3.unk0 = 0;
    a3.unk4 = 0;
    a3.unk8 = 1;
    slot.itemFlags = ITEM_FLAG_EXISTS;
    sub_8090E14(gUnknown_202DE58, &slot, &a3);
    xxx_format_and_draw(4, 3, gUnknown_80DD958, r0, 0);
    sub_80073E0(r0);
}

u32 sub_8027D9C(struct PokemonStruct *r0)
{
    u32 var1;
    if(r0->isLeader == 0)
    {
        var1 = 0;
        if(r0->unk4.dungeonIndex == 0x41)
            var1 = 1;
            if(var1 != 0)
            {
                if(sub_80023E4(8) == 0)
                    return 0;
            }
    }
    else
        return 0;
    return 1;
}

u32 sub_8027DCC(struct PokemonStruct *r0)
{
    u32 var1;
    if(sub_808D3BC() != r0)
        if(sub_808D3F8() != r0)
            if(r0->isLeader == 0)
            {
                var1 = 0;
                if(r0->unk4.dungeonIndex == 0x41)
                    var1 = 1;
                if(var1 != 0)
                {
                    if(sub_80023E4(8) != 0)
                        goto check;
                }
                else
                {
                    check:
                    if(sub_8027E18(r0) != 3)
                        return 1;
                }
            }
    return 0;
}

u32 sub_8027E18(struct PokemonStruct *r0)
{
    if(r0->heldItem.itemIndex == 0)
        return 0;
    else if(GetNumberOfFilledInventorySlots() < INVENTORY_SIZE)
        return 1;
    else if(sub_8027E4C(r0))
        return 2;
    else
        return 3;
}

u8 sub_8027E4C(struct PokemonStruct *r0)
{
    if(!IsNotMoneyOrUsedTMItem(r0->heldItem.itemIndex))
        return 0;
    else
    {
        if(IsThrowableItem(r0->heldItem.itemIndex))
        {
            if(gTeamInventory_203B460->teamStorage[r0->heldItem.itemIndex] + r0->heldItem.numItems > 0x3e7)
                return 0;
        }
        else if(gTeamInventory_203B460->teamStorage[r0->heldItem.itemIndex] > 0x3e6)
        {
            return 0;
        }
    }
    return 1;
}

void sub_8027EB8(void)
{
    switch(sub_8027E18(gUnknown_203B2BC->unk18))
    {
        case 1:
            PlaySound(0x14d);
            AddHeldItemToInventory(&gUnknown_203B2BC->unk14);
            FillInventoryGaps();
            gUnknown_203B2BC->unk14.itemIndex = 0;
            gUnknown_203B2BC->unk14.numItems = 0;
            GivePokemonItem(gUnknown_203B2BC->targetPoke, &gUnknown_203B2BC->unk14);
            SetFriendAreaActionMenuState(6);
            break;
        case 2:
            PlaySound(0x14d);
            if(IsThrowableItem(gUnknown_203B2BC->unk14.itemIndex))
                gTeamInventory_203B460->teamStorage[gUnknown_203B2BC->unk14.itemIndex] += gUnknown_203B2BC->unk14.numItems;
            else
                gTeamInventory_203B460->teamStorage[gUnknown_203B2BC->unk14.itemIndex] += 1;
            gUnknown_203B2BC->unk14.itemIndex = 0;
            gUnknown_203B2BC->unk14.numItems = 0;
            GivePokemonItem(gUnknown_203B2BC->targetPoke, &gUnknown_203B2BC->unk14);
            SetFriendAreaActionMenuState(7);
            break;
        case 0:
        default:
            SetFriendAreaActionMenuState(2);
            break;
    }
}

