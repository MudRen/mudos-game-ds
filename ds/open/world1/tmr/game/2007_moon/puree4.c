#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("深海棗泥(jujube puree) [淨重 %d 公克]",query("time") );
}

void create()
{
        set_name(RED "深海棗泥" NOR,({"jujube puree", "puree", "_MOON_PUREE_"}) );
        set("long",@LONG
棗泥是由去核乾棗所打成的，味道香濃綿細、不甜不膩、口感非常滑順，
是做月餅的重要材料之一
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                  set("unit","團");
        }
        set("value", 100);
        set("time", 500 + random(500) );

        setup();
        set("long", query("long") + getLong() );
}

