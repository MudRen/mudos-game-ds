#include <ansi.h>
 
inherit ITEM;
 
void create()
 
{
 
        set_name(GRN"八岐大蛇"RED"．"HIG"綠首"NOR,({"orochi green head","green","head"}));
        set("long",GRN"八岐大蛇"RED"之"HIG"綠首\n"NOR);
        set_weight(10000); 
        set("value",10000);
        set("unit","顆"); 
        setup();

}

