#include <ansi.h>
inherit NPC;
void create()
{
 set_name("老人",({"old man","man"}));
 set("long",@LONG
一個滿面皺紋的老人.
LONG
    );
 set("attitude", "peaceful");
 set("age",72);
 set("gender","男性");
 set("level",20);
 set_skill("sky-dagger",20);
 set("chat_chance_combat",200);
 setup();
}