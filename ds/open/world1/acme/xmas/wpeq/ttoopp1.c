//聖誕活動第一名 志狼(ttoopp) 禮物 -by tmr-

#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
          set_name(HIR "狂龍" HIC "喇叭褲" NOR ,({ "ttoopp pants","pants"}) );
        set("long",
"聖誕活動第一名 志狼所得獎的禮物。\n"
"這是一件上面繡著狂龍圖案的喇叭褲,似乎代表著什麼意義.........\n"
);
        set_weight(1200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "fur");
                set("unit", "件" );
                set("value",2500);
                set("valme",3);
                set("no_sac",1);
                set("armor_prop/armor", 10);
                set("armor_prop/con",1);
        }
        setup();
}

int query_autoload() { return 1; }


