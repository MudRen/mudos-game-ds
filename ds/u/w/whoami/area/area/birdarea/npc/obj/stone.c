#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIG"五"HIW"彩"HIC"石"NOR,({ "five color stone","stone" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","這是一顆擁有五種顏色的石頭，在夜晚也有照明的功\能。\n");
                set("unit","顆");
                set("value",5000);
        }
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

