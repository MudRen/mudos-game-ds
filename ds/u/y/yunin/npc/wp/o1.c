#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIC"�A���C"NOR, ({ "jian lie sword","sword" }) );
        set_weight(19000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIC"�ѤU���L�A�ߧڿA���C\n"NOR);
                set("value",10000);
                set("volume",5);
                set("weapon_prop/con",1);
}

        init_sword(50);
    setup();
}
