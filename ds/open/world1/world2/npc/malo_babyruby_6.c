inherit NPC;
void create()
{
	set_name("�p����",({"kid ruby","kid","ruby"}) );
	set("long",@LONG
�@�Ӥѯu���p�Ĥl�A���b���ۧ�t����إ߰�a���C���C
LONG);
	set("age",18);
	set("level",12);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�ݨ����٤��U��??");
	setup();
	carry_object(__DIR__"../wp/wood_staff_5")->wield();
	carry_object(__DIR__"../eq/cloth_cloak_3")->wear();
	carry_object(__DIR__"../eq/cloth_pants_5")->wear();

	add_money("dollar",90);
}

void die()
{
	message_vision("$N�{�����e��: ��..�A�ۭt��..�ڭn�s��L��a�q�r�A!!\n",this_object());
	::die();
}
