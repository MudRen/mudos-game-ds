#include <ansi.h>
inherit NPC;
void create()
{
        set_name("路人" , ({ "man" }) );
        set("level",2);
         set("race","人類");
         set("gender","男性");
        set("age",35);
        set("long","他是一位路過此地的路人。\n");
        setup();
         add_money("coin",150);
}
