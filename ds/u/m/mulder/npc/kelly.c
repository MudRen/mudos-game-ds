// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���z�Y" , ({"Kelly Chan", "Kelly" }) );
	set("long", "�o�M�ۨӱ��X�`�Ю��l�M�p��z�I�I\n");
	set("gender", "�k��");
	set("race", "�H��"); 
	set("age", 24);
	set("level", 120);
	set_skill("sword", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("unarmed", 150);
	set("title", "�u�o�O�`�Ю��l���n�B�͡I�I�v");
		
	setup();
	carry_object("/obj/longsword.c")->wield();

}
