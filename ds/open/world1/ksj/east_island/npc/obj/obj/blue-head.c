#include <ansi.h>
 
inherit ITEM;
 
void create()
 
{
 
        set_name(GRN"八岐大蛇"RED"．"HIC"青首"NOR,({"orochi blue head","blue","head"}));
        set("long",GRN"八岐大蛇"RED"之"HIC"青首\n"NOR);
        set_weight(10000); 
        set("value",10000);
        set("unit","顆"); 
        setup();

}

