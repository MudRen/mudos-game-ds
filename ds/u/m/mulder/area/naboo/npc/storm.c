#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIW "stormtrooper" NOR , ({"stormtrooper"}) );
	set("long", " 
�L�W��ۤ@�M�������˥ҡA�M�رa�@�K�B�j�A
��ӥL�O�Ұꪺ�x���C
\n");
	set("race", "�H��");
	set("gender", "�k��");
	set("age", 25);
	set("attitude", "heroism");
	set("level", 25);
	set("evil", 30);
	set("combat_exp",3000);
	set_skill("gun",50 );
	set("title",MAG"�Ұ곡��"NOR);
	set_skill("dodge", 40);
	set_skill("parry", 30);
	set_skill("unarmed",20);
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
	(:command("say �h���a�c��I�I"):),
	(:command("�ӤH�ڡI���q�x�ڡI"):),
	(:command("reload clip"):),
	(:command("ss"):),	
	}) );
	
	
	setup();
	carry_object(__DIR__"wp/blaster")->wield();
	carry_object(__DIR__"wp/bclip");
	carry_object(__DIR__"wp/bclip");
	carry_object(__DIR__"wp/bclip");
	
}

