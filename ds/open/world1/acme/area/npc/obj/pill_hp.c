#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIW "還魂丹" NOR , ({ "hp pill", "pill" }));
        set("long","一顆能起死回生的丹藥。\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "粒");
        }
        set("heal",([
         "hp" : 1000,
         ]));
        set("value", 500);
        setup();
}
