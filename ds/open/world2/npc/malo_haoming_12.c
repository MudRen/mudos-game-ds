inherit NPC;
void create()
{
	set_name("���q��",({"Haoming in","haoming","in"}) );
	set("long",@LONG
�@�ӵL�ҬO�ƪ���¾�͡A�w�g���~�F�@�q�ɶ��A����O���q�ʩM���x�y�A
�����ۨ�B��k�ͷf�S�C
LONG);
	set("age",18);
	set("level",12);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�q�q�ݧڤ��Ѭ擄���C�⪺���ǰڡC");
	setup();

	carry_object(__DIR__"../eq/cloth_clothes_7")->wear();
	carry_object(__DIR__"../eq/cloth_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_pants_7")->wear();

	add_money("dollar",140);
}

void die()
{
	message_vision("$N�{�����e��: ���شN�ӬD�氫�Ѥ�!!\n",this_object());
	::die();
}
