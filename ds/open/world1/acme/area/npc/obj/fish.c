#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIR "生魚" NOR , ({ "fish" }));
        set("long","一隻未煮熟的生魚，你想「活魚三吃」嗎？\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "隻");
        }
        set("heal",([
         "hp" : 15,
         "ap" : 15,
         ]));
        set("value", 150);
        setup();
}
