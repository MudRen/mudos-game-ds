
inherit NPC;

void create()
{
	set_name("ĵ�ö���",({"leader"}) );
	set("long","�o�Ӷ����O��`��ĵ�áA�L�ݤW���������L��ģ�@���l�F�C\n");		
	set("age",39);
	set("level",32);
	set("race","�H��");
	set("evil",-5);
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",10);
	set("chat_msg",({
		(:command("say ��������Z�}���A�ȡA�u�O�ڳ̤j���a���C"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڡAĵ�ö����A�n�N�@�ê̴N�a���k�I�I"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_skill("fork",70);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	carry_object(__DIR__"wp/speedlance")->wield();
	carry_object(__DIR__"eq/patrolhelmet")->wear();

	add_money("coin",50);
}