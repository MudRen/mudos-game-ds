inherit NPC;

void create()
{
	set_name("�y�]",({"vag"}) );
	set("long",
		"�@�ӬݨӬy���y�𪺳å�A�����h�n�N�a�ݵۧA..�C\n"
	);		
	set("age",23);
	set("level",3);
      set("attitude", "heroism");

	set("evil",40);		
	set("race","�H��");

	set("chat_chance",10);
	set("chat_msg",({
                (:command("say �e���l��Ĺ�F�ʨӨ�A�u�����������n�B�I"):),
		(:command("hehe"):),
	})	);

        set("chat_chance_combat", 17);
   	set("chat_msg_combat", ({
	(:command("say �Ѥl����N���A���Ѩ��Ѧ󬰡u�y�]���k�v�I�I"):),
         }) );
	set_skill("dodge",10);
	set_skill("parry",10);
	set_skill("blade",5);
	set_skill("unarmed",5);
	
	setup();
	carry_object(__DIR__"wp/knife")->wield();
	carry_object(__DIR__"eq/furrier")->wear();
	carry_object(__DIR__"obj/dice");
	add_money("coin",50);
}
