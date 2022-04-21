#include "item.h"
#include "physics.h"
#include "sound.h"
#include "functions.h"
#include "playeritem.h"
#include "functions.h"

void sub_08075FF8(ItemBehavior*, u32);
void sub_08076488(ItemBehavior*, u32);
void sub_08076518(ItemBehavior*, u32);
void sub_080765E0(ItemBehavior*, u32);

void ItemBomb(ItemBehavior* this, u32 idx) {
    static void (*const stateFuncs[])(ItemBehavior*, u32) = {
        sub_08075FF8, NULL, sub_08076488, sub_08076518, sub_080765E0,
    };
    stateFuncs[this->stateID](this, idx);
}

void sub_08075FF8(ItemBehavior* this, u32 idx) {
    static const s8 gUnk_0811BDAC[] = {
        0, -8, 4, -1, 0, 2, -4, -1,
    };
    Entity* entity;
    u32 maxBombs;
    u32 bombCount;
    const s8* pos;
    s32 x;
    s32 y;

    if ((gPlayerState.jump_status | gPlayerState.field_0x3[1]) == 0) {
        bombCount = 0;
        for (entity = FindEntityByID(PLAYER_ITEM, PLAYER_ITEM_BOMB, 2); entity != NULL;
             entity = FindNextDuplicateID(entity, 2)) {
            bombCount++;
        }
        maxBombs = this->behaviorID == 7 ? 3 : 1;
        if (maxBombs > bombCount) {
            entity = CreatePlayerItemWithParent(this, 2);
            if (entity != NULL) {
                pos = &gUnk_0811BDAC[gPlayerEntity.animationState & 6];
                PositionRelative(&gPlayerEntity, entity, Q_16_16(pos[0]), Q_16_16(pos[1]));
                ModBombs(-1);
                SoundReq(SFX_PLACE_OBJ);
            }
        }
    }
    DeletePlayerItem(this, idx);
}

ASM_FUNC("asm/non_matching/itemBomb/sub_08076088.inc", void sub_08076088(ItemBehavior* this, void* arg1))
