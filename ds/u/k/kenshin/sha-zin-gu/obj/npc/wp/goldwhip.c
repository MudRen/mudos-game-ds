#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIY"���t�@"NOR, ({ "gold whip", "whip" }));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�v�騦���v�ũҥ��y���@�A���@�W�Q�L��A���O�l�D�����A�ҥH�u�A�X����@���H�M�ΡC\n");
                set("value", 2000);
                set("material", "steel");
}
        init_whip(32);
        set("weapon_prop/sou", 1);
                setup();
}

