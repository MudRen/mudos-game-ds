#include <ansi.h>
inherit NPC;
void create()
{
        set("title","袁家村" );
        set_name("村婦" , ({ "woman" }) );
        set("level",8);
        set("race","人類");
        set("gender","女性");
        set("age",27);
        set("long","在河邊洗衣物的村婦。\n");
        setup();
add_money("coin", 100);
}
