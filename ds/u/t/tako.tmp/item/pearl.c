#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"琉璃"HIW"片"NOR, ({ "liu lieh","lieh" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一片淡藍色的小玻璃片,但又有一種說不出的透明感
     ，在夜晚的時侯會散出螢光。\n");
                set("unit", "片");
                set("value",100);
        }
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}


