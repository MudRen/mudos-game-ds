#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIR"�K���M"NOR, ({ "fire blade", "blade" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�v�騦���v�ũҥ��y���M�A���M���W�Q�A���O�l�D�����A�ҥH�u�A�X��ߤM���H�M�ΡC\n");
                set("value", 2000);
                set("material", "steel");
}
        init_blade(30);
        set("weapon_prop/sou", 1);
                setup();
}

