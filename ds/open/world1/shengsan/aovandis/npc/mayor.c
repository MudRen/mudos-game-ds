
inherit NPC;

void create()
{
	set_name("���Z�}������",({"mayor"}) );
	set("long",
"�o�쥫�����۷��R�L���������A�Mħ�i�˪����e���Aı�o�L�O��n�����C\n"
	);		
	set("age",45);
	set("level",20);
	set("attitude", "heroism");
	set("race","�H��");
	set("evil",-20);
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �w��Ө���Z�}���A�o�O�y���R�������A�кɿ������a�I"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 17);
	set("chat_msg_combat", ({
		(:command("say �ϩR�ڡA���H�y�ϤF�I�I"):),
	}) );
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("unarmed",50);

	setup();

	carry_object(__DIR__"eq/redglazedring")->wear();
	add_money("coin",50);
}