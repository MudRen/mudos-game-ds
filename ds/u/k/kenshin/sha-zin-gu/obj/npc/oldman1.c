#include <ansi.h>
inherit NPC;
void create()
{
        set_name("老人甲" , ({ "old-man","man" }) );
        set("level",1);
        set("race","人類");
        set("gender","男性");
        set("age",67);
        set("long","愛下棋的老人之一。\n");
        set("chat_chance", 5);
        set("chat_msg", ({
             "老人甲說:老人丙你到底會不會下啊??\n",
                       }));

                setup();
        
}

