#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name(YEL"�����"NOR, ({ "wood axe", "axe" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�v�騦���v�ũҥ��y����A���򭱾W�Q�A���O�l�D�����A�ҥH�u�A�X��ߩ򪺤H�M�ΡC\n");
                set("value", 2000);
                set("material", "steel");
}
        init_axe(32);
        set("weapon_prop/wit", 1);
                setup();
}

