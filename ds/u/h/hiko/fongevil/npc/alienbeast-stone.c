#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIW"異"HIC"獸"HIW"石"NOR, ({ "alien-beast stone", "stone" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long",
        "一個半邊是龍半邊是虎的石刻，上面寫著古文，似乎是不尋常\n"
        "之物，也許\該找人翻譯看看上面得古文，而且龍虎雕紋之間有\n"
        "一條小裂痕，也許\可以將其分開\n");
                set("unit", "顆");
                set("value",100);                
        }
        setup();
}




