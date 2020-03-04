// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIC "�`�Ю��l" NOR , ({"Kyoko Fukada", "kyoko" }) );
	set("long", "�o�O�饻���s�i���P�A�]�O�p��z�̷R���H�I�I\n");
	set("race", "�H��");
	set("gender", "�k��");
	set("age", 16);
	set("level", 120);
	set_skill("sorgi_sword", 250);
	set_skill("sword", 200);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("combat", 200);
	set_skill("unarmed",150);
	set("title", "�y�o�O�p��z���k�B�͡z");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
            (:command("exert sorgi_sword"):),
            }) );

	
	setup();
	carry_object("/u/m/mulder/area/npc/wp/finalsword.c")->wield();
	carry_object("/obj/cloth.c")->wear();
	carry_object("/u/l/luky/obj/fighterneck.c")->wear();
	
}
void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("id") != "mulder")
        
 {	
	message_vision("�`�Ю��l��$N���D�G" HIW "�A�n!�A�n....^_^�C\n" NOR,me);
        command("wink" + me->query("id"));
	
 }
	 
	else
 {
	command("say �p��z�ڦn�����A�r^��^\n");
	command("wink mulder");
	command("kiss mulder");
 }
 }


