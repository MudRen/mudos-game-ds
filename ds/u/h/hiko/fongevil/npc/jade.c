#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(MAG"四魂之玉"NOR, ({ "four-soul jade", "jade" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long",
        "一枚很奇特的玉石，隱隱有藍光閃現，傳說是妖怪之寶，\n"
        "封印著遠古創世魂的碎片，看來不是凡物，在聚陰之地有\n"
        "著強烈的效果\n");
                set("unit", "枚");
                set("value",0);
                set("no_auc", 1);
                set("no_sell",1);                
                set("no_put",1);
        }
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}


