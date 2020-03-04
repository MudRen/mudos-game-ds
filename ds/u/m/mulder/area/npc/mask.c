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
	set("level", 20);
	set("max_hp", 500);
	set("max_mp", 100);
	set("attitude", "aggressive");
	set("str", 30);
	set("evil", 99);
	set("combat_exp",2000);
	set_skill("fork", 20);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("unarmed", 60);
	set("title", "�y���H�p�¡z"); 
            set("chat_msg_combat", ({
            (:command("hehe"):),
            }) );

 
	
	setup();
	carry_object("/u/s/sopher/area/npc/npcwp/light_spear.c")->wield();
	carry_object("/u/m/mulder/area/npc/eq/armor.c")->wear();
	
}

