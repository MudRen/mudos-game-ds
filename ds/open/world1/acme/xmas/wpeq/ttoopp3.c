//聖誕活動第一名 志狼(ttoopp) 禮物 -by tmr-

#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("神奇護膝" ,({ "ttoopp leggings","leggings" }) );
        set("long",
"聖誕活動第一名 志狼所得獎的禮物。\n"
"這是一件神奇的護具，聽說穿上它的人將擁有神奇的力量。\n"
);
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "fur");
                set("unit", "雙" );
                set("value",1000);
                set("valme",1);
                set("no_sac",1);
                set("armor_prop/armor", 12);
                set("armor_prop/dex",1);
        }
        setup();
}

int query_autoload() { return 1; }


