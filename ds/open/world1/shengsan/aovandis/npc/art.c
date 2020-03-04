inherit NPC;

void create()
{
	set_name("�ȯS",({"art"}) );
	set("long","�ȯS�O���Z�}�����u�ö��`�q�O�A�L����ɭ���Q��L�u�ö��������Ҫ֩w�C\n");		
	set("age",40);
	set("level",30);
	set("attitude", "heroism");
	set("race","�H��");
	set("evil",-20);	// ���c�� -20 (�������c, �t���})
	set("exp_point",3);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �u�@�o�y���R�������O�ڪ��d���I"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 17);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڡA�u�ö��`�q�O�A�n�N�@�ê̴N�a���k�I�I"):),
	}) );
	set_skill("dodge",60);
	set_skill("block",60);
	set_skill("parry",50);
	set_skill("unarmed",50);
	set_skill("sword",80);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	set("inquiry/name","�A�n�A�ڬO���Z�}�����u�ö��`�q�O�A�W�s�ȯS");
	setup();

	carry_object(__DIR__"wp/artsword")->wield();
	carry_object(__DIR__"eq/drangonshield")->wear();
	add_money("coin",50);
}