#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit FORK;
inherit F_UNIQUE;

void create()
{
        set_name( HIR "丈二紅槍" NOR,({"red pike", "pike"}) );
        set("long",@LONG
燎原槍法是厲若海的成名絕技，而丈二紅槍則是他的專屬武器。
LONG
        );
        set_weight(8000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","桿");
                set("value",16000);
                set("volume", 2);
                 set("material", "gold");
                set("limit_level", 30);
                set("limit_skill", 80);
        }
        set("replica_ob",__DIR__"red-pike2");
        set("weapon_prop/shield",10);
        set("weapon_prop/armor",10);
        set("weapon_prop/bio", -1);
        set("weapon_prop/sou", 1);
        set("weapon_prop/int", 1);
        set("weapon_prop/str", 1);
        init_fork(65);
        setup();        
}

