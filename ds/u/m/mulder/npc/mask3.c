// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIR "�X���H" NOR , ({"super mask", "mask" }) );
	set("long", " �L�O�Ӧۤ��P�ɶ�������A�A�i�ন���L�t�@�ӥؼСI\n");
	set("race", "�H��");
	set("gender", "�k��");
	set("age", 30);
	set("level", 120);
	set("max_hp", 100000);
	set("max_mp", 100000);
	set("attitude", "killer");
	set("evil", 999);
	set("combat_exp",20000);
	set_skill("sword", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set("title", "�y���H���w���z");
	set_spell("mindkill",100);      
            set("chat_chance_combat", 100);
            set("chat_msg_combat", ({
            (:command("servenkill "):),
            }) );
	
	setup();
	carry_object("/u/t/tmr/test/sword.c")->wield();
	
}

