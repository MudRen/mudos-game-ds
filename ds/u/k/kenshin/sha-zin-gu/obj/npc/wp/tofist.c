#include <weapon.h>
#include <ansi.h>

inherit FIST;

void create()
{
        set_name(HIG"�g����"NOR, ({ "to claw", "claw" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�v�騦���v�ũҥ��y�����A�����W�Q�A���O�l�D�����A�ҥH�u�A�X��ߤ����H�M�ΡC\n");
                set("value", 2500);
                set("material", "steel");
}
        init_fist(31);
        set("weapon_prop/wit", 1);
                setup();
}


