#include <ansi.h>
inherit NPC;
void create()
{
        set_name("旅人" , ({ "traveler" }) );
        set("level",4);
        set("race","人類");
         set("gender","男性");
        set("age",35);
        set("long","他是一位正在趕路的旅人。\n");
        set("chat_chance", 3 );
        set("chat_msg",({
           "旅人說道：快到了！東邊不遠處就是天城了。\n",
           (:command("sweat"):),
        }) );
        setup();
}

