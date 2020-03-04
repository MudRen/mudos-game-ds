// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("陳慧琳" , ({"Kelly Chan", "Kelly" }) );
	set("long", "她專誠來探訪深田恭子和小喇叭！！\n");
	set("gender", "女性");
	set("race", "人類"); 
	set("age", 24);
	set("level", 120);
	set_skill("sword", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("unarmed", 150);
	set("title", "「她是深田恭子的好朋友！！」");
		
	setup();
	carry_object("/obj/longsword.c")->wield();

}
