#include <ansi.h>
inherit NPC;
void create()
{
        set_name("探險者" , ({ "adventurer" }) );
        set("level",10);
 set("race", "人類");
    set("chat_chance",10);
        set("age", 50);
        set("long","一個探險者，他似乎正在這附近探索。\n");
        setup();
}

