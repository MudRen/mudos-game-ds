#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIC"���R�C"NOR, ({ "water-dance sword", "sword" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�v�騦���v�ũҥ��y���C�A���C�W�Q�L��A���O�l�D�����A�ҥH�u�A�X��ǼC�h�M�ΡC\n");
                set("value", 1700);
                set("material", "steel");
}
        init_sword(30);
        set("weapon_prop/tec", 1);
                setup();
}

