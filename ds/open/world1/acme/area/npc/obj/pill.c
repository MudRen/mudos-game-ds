#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIR "紅心丹" NOR , ({ "red heart pill", "pill" }));
        set("long","這是一顆外表火紅的丹藥，是顆少見的靈丹，能夠恢復你\n"
                   "的體力和內力。\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "粒");
        }
        set("heal",([
         "hp" : 30,
         "ap" : 70,
         ]));
        set("value", 500);
        setup();
}
