#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIR"狂戰士"NOR, ({"berserker"}) );
	set("long", "你可以試試pk他\n");
	set("race", "人類");
	set("age", 24);
        set("level",50);
        set("attitude", "heroism");
        set_skill("parry",100);
        set_skill("dodge",100);
set_skill("mirage-steps",100);
        set_skill("sword",100);
set_skill("hungchen-sword",100);
    	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(:command,"exert hungchen-sword":),
(:command,"exert mirage-steps":),
}) );
        	
	setup();
	carry_object("/u/s/sonicct/finalsword.c")->wield();
}


