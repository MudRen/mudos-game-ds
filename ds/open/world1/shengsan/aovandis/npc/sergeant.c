
inherit NPC;

void create()
{
	set_name("���x",({"sergeant"}) );
	set("long","�L�O���Z�}���̪����x�C\n");		
	set("age",30);
	set("level",40);
	set("race","�H��");
	set("guild_gifts",({3,4,8,5}));
	set("evil",-10);
	set("exp_point",4);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �o�O�y���R�������A�Ф��n���X�H�k���Ʊ���I"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڨ������x�A�@�w�n�N�@�ê̴N�a���k�I�I"):),
		(:command("cast mindkill"):),
		(:command("cast mindkill"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_spell("mindkill",70);
	set_skill("staff",70);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	carry_object(__DIR__"eq/aihun_robe")->wear();

	add_money("coin",50);
}