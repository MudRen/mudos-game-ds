#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIW "內轉丹" NOR , ({ "ap pill", "pill" }));
        set("long","恢復內傷，增強內勁之丹藥。\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "粒");
        }
        set("heal",([
         "ap" : 500,
         ]));
        set("value", 500);
        setup();
}
