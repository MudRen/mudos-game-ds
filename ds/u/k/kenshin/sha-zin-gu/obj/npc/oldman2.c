#include <ansi.h>
inherit NPC;
void create()
{
        set_name("老人丙" , ({ "old-man","man" }) );
        set("level",1);
        set("race","人類");
        set("gender","男性");
        set("age",73);
        set("long","愛下棋的老人之一。\n");
        set("chat_chance", 5);
        set("chat_msg", ({
             "老人丙說:老人甲是你不會下吧!!\n",
                       }));

                setup();
        
}

