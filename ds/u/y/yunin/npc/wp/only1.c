#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"�A���C��"NOR, ({ "jian lie sword","sword" }) );
        set_weight(19000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIC"�ѤU���L�A�ߧڿA���C\n"NOR);
                set("value",10000);
                set("volume",5);
        set("replica_ob",__DIR__"o1");
        }
    set("weapon_prop/str",5);
    set("weapon_prop/dex",1);
    set("weapon_prop/hit",10);
    set("weapon_prop/con",4);
        init_sword(78);
    setup();
}
