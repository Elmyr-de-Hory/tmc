#include "global.h"
#include "functions.h"
#include "entity.h"

extern Entity gLinkEntity;

extern void (*gUnk_0810FF5C[])(Entity* this);
extern void (*gUnk_0810FF64[])(Entity* this);

void sub_0806581C(Entity* this) {
    if (this->flags & 0x2) {
        gUnk_0810FF64[this->action](this);
    } else {
        gUnk_0810FF5C[this->action](this);
        if (this->action != 0) {
            sub_0806ED78(this);
        }
    }
}

void sub_08065864(Entity* this) {
    this->action = 1;
    this->spriteSettings.b.ss0 = 1;
    LoadAnimation(this, 0xC);
}

void sub_08065880(Entity* this) {
    sub_080042B8(this);
}

void sub_08065888(Entity* this) {
    this->action = 1;
    this->spriteSettings.b.ss0 = 1;
    this->animationState = 4;
    this->field_0x68 = sub_0801E99C(this);
    sub_08078784(this, this->field_0x68);
    sub_0807DD50(this);
}

void sub_080658BC(Entity* this) {
    if (this->interactType == 2) {
        this->action = 2;
        this->interactType = 0;
        LoadAnimation(this, sub_0806F5A4(sub_080045C4(this, &gLinkEntity)));
        sub_0806F118(this);
    } else {
        sub_0807DD94(this, 0);
    }
}

void sub_08065900(Entity* this) {
    if (UpdateFuseInteraction() != 0) {
        this->action = 1;
    }
}

void sub_08065914(Entity* this) {
    Entity* target;

    target = sub_0805EB00(7, 0x1F, 7);
    if (target != NULL) {
        PositionRelative(this, target, 0x180000, -0x10000);
        target->parent = this;
    }
    target = sub_0805EB00(7, 0x20, 7);
    if (target != NULL) {
        PositionRelative(this, target, 0x280000, 0);
        target->parent = this;
    }
}

void sub_08065960(Entity* this) {
    if (this->action == 0) {
        this->action++;
        this->spriteSettings.b.ss0 = 1;
        LoadAnimation(this, 0xC);
    } else {
        sub_080042B8(this);
    }
}