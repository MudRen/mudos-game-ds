#include <ansi.h>
 
inherit ITEM;
 
void create()
 
{
 
        set_name(GRN"八岐大蛇"RED"．"NOR"灰首"NOR,({"orochi grey head","grey","head"}));
        set("long",GRN"八岐大蛇"RED"之"NOR"灰首\n"NOR);
        set_weight(10000); 
        set("value",10000);
        set("unit","顆"); 
        setup();

}

