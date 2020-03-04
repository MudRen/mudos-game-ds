#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("礦工頭" , ({ "mineral collector","collector" }) );
        set("long",@long
他是這個礦區的工頭，專門收購礦工所採集而到的礦物。他看起來相
當的友善，正微笑地對你點頭，然後又埋頭處理滿地的礦物，看起來相當
的勤勞。
long
);
        set("level",5);
        set("race","人類");
        set("age", 33);
        set("attitude", "peaceful");   //溫和的 NPC。
        set("storeroom",__DIR__"mineralroom"); //注意. 要建立一個room放東西
        setup();
}
void init()
{
        add_action("do_sell","sell");
}

