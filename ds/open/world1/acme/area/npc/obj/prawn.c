#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIR "小蝦" NOR , ({ "prawn" }));
        set("long","一隻未煮熟的小蝦，你想「生蝦二吃」嗎？\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "隻");
        }
        set("heal",([
         "hp" : 10,
         "ap" : 10,
         ]));
        set("value", 100);
        setup();
}
