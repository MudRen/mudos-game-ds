// weapon: /z/xingxiu/npc/obj/wandao.c
// Jay 3/17/96

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("���ԧB�s�M", ({ "arabia blade", "blade" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "�`");
                set("long", "�o�O�@�`�G�̮̪����ԧB�s�M�A�M���e�s�몬�C");
                set("value", 1500);
                set("material", "steel");
        }
        init_blade(25);
        setup();
}

