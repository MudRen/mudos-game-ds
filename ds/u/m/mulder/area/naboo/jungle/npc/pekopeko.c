#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIB"������"NOR, ({"peko peko","peko"}) );
        set("race", "���~");
        set("age",20);
        set("level",14);
        set("attitude","peaceful");
        set("dex",30);
      set("str",20);
      set_temp("fly",1);		        
        set("long",HIB"�������O�@�����Υ��j�M�Q���ӱ��������C\n"NOR);
        set("limbs", ({ "�Y��", "����", "��}", "����","�ͻH" }) );
        set("verbs", ({ "poke", "claw" }) );
        set("chat_chance",70);
        set("chat_msg",({
	(: "random_move" :),
        }) );
      set_skill("mob_bite",20);
      set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	        (:command("exert mob_bite sacer"):),
       	 }) );
        setup();
}

 