inherit NPC;

void create()
{
	set_name("����ĵ��",({"patrol"}) );
	set("long","�@��ĵ�å��b�o�̨��ޡC�o��ĵ�åR���F���q�P�C\n");		
	set("age",30);
	set("level",24);
	set("race","�H��");
	set("evil",-5);
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say ��H�_�ǡA�ڤ߷R��ĵ���]����h�F�O�H"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڡA����ĵ�áA�n�N�@�ê̴N�a���k�I�I"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_skill("staff",70);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	carry_object(__DIR__"wp/patrolbaton")->wield();
	carry_object(__DIR__"eq/patrolarmor")->wear();

	add_money("coin",50);
}