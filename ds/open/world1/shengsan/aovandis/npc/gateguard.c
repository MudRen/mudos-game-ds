
inherit NPC;

void create()
{
	set_name("�����u��",({"guard","gate guard"}) );
	set("long","���@�Ӧu�å��b�o�̺ʵ��۶i�X�������i�äH���C\n");		
	set("age",25);
	set("level",25);
	set("race","�H��");
	set("evil",-5);
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",10);
	set("chat_msg",({
		(:command("say �w��Ө���Z�}���A�o�O�y���R�������A�Ф��n���X�H�k���Ʊ���I"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڨ��������u�áA�n�N�@�ê̴N�a���k�I�I"):),
	}) );
	set_skill("dodge",60);
	set_skill("block",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	set_skill("axe",40);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	carry_object(__DIR__"wp/typicalaxe")->wield();
	carry_object(__DIR__"eq/typicalshield")->wear();
	carry_object(__DIR__"eq/typicalboot")->wear();

	add_money("coin",50);
}