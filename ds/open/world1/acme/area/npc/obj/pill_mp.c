#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIW "淨心丹" NOR , ({ "mp pill", "pill" }));
        set("long","能夠讓人的心靈受到淨化，增強魔力。\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "粒");
        }
        set("heal",([
         "mp" : 500,
         ]));
        set("value", 500);
        setup();
}
