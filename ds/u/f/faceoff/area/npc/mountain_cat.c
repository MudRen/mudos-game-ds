#include <ansi.h>
inherit NPC;
void create()
{
 set_name("山貓",({"cat",}));
 set("long",@LONG
一種常在山區見到的貓科動物.
LONG
    );
 set("race","野獸");
 set("attitude", "peaceful");
 set("level",14);
 set("limbs", ({ "頭部", "身體", "尾巴" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
}
