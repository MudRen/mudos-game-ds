#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIW "Naboo城"HIY"居民" NOR , ({ "naboo citizen","citizen"}) );
        set("race","人類");
        set("gender","男性");
        set("age",25);
        set("level",15);
        set("long",HIW "這個是住在Naboo城的居民 \n"NOR);
        set("chat_chance",70);
        set("chat_msg",({
	(: "random_move" :),
        }) );
        setup();
}