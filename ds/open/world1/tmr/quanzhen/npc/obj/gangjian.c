// gangjian.c

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("���C", ({ "jian", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "�`");
                set("long", "�o�O�@�`��u������C�A�o�ؼC�b�N�⤧���D�`�y��C\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N�u�|�v���@�n��X�@�`$n���b�⤤�C\n");
                set("unwield_msg", "$N�N�⤤��$n���^�C�T�C\n");
        }
        init_sword(30);
        setup();
}
