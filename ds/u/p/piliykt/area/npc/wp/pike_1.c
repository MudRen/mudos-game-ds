#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
        set_name(WHT"銀槍"NOR, ({ "wht pike","pike" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這把槍的全身上下是用上好的白銀所打製而成.\n");                                      
                set("value",3000);
                set("material", "silver");
        }
    set("limit_lv",10);
    set("limit_con",15);
    set("limit_str",20);
    set("weapon_prop/str",1);
    set("weapon_prop/con",1);
    set("weapon_prop/dex",-1);
    init_fork(35);
    setup();
}



