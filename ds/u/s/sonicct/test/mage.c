#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIR"咒術師"NOR, ({"mage"}) );
	set("long", "你可以試試pk他\n");
	set("race", "人類");
	set("age", 24);
	set("level", 50);
        set("attitude", "heroism");
set_spell("god-fire",150);
set_spell("recite-sutra",100);
set_skill("gun",100);
set("chat_chance_combat", 70);
set("str",100);
        set("chat_msg_combat", ({
        (:command,"cast god-fire":),
(:command,"cast recite-sutra":),
(:command,"shoot":),
        }) );
        set("chat_chance",80);
        set("chat_msg",({
  (: command("reload clip") :),
}));
        	
	setup();
carry_object("/u/s/sonicct/test/finalgun.c")->wield();
carry_object("/u/s/sonicct/test/finalclip.c");
}

