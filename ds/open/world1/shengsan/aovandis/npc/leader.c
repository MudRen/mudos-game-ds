
inherit NPC;

void create()
{
	set_name("�u�ö�����",({"leader"}) );
	set("long","�L���b�o�̨��ޡA�H�T�O�������w���C\n");		
	set("age",29);
	set("level",22);
	set("race","�H��");
	set("evil",-5);
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",3);
	set("chat_msg",({
		(:command("say ť���̪�`�`���@�s�����W���Ǫ��X�S�b���Z�}�������~�A�ЦU��ȫȭn�p�ߡI"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڡA�u�ö������A�n�N�@�ê̴N�a���k�I�I"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_skill("sword",30);

	set("talk_reply","��Ať���̪�`�`���@�s�����W���Ǫ��X�S�b���Z�}�������~�C�ڷ|�ɤO�O�@�o�y�������C");
	setup();

	carry_object(__DIR__"wp/typicalsword")->wield();
	carry_object(__DIR__"eq/typicalwrists")->wear();
	carry_object(__DIR__"eq/typicalhelmet")->wear();
	carry_object(__DIR__"eq/typicalglove")->wear();

	add_money("coin",50);
}