#include <ansi.h>
inherit NPC;
void create()
{
 set_name("俠客",({"bagi ranger","ranger"}));
 set("long",@LONG
一個來到十萬大山除盜的八極門俠客.
LONG);
 set("title",HIR"八極門"NOR);
 set("age",30);
 set("gender","男性");
 set("level",20);
 set_skill("bagi_fist",20);
 set_skill("unarmed",20);
 set("chat_chance_combat",200);
 set("chat_msg_combat",({
    (:command,"exert bagi_fist":),
 }));
 setup();
}

