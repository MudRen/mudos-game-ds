inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("���ʱ]",({"james chen","chen","james"}) );
	set("long",@LONG
�@�Ӭ�s�Ҿǥ͡A�Q���߷R�n�u���֡A�S�ܷ|�A�_�A�ҥH���ӥ~���s���_���C
LONG);
	set("age",26);
	set("level",16);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","���ؤj�ǯu�O�����ɶI�͡A���C");
	setup();

	carry_object(__DIR__"../eq/cloth_clothes_8")->wear();
	carry_object(__DIR__"../eq/cloth_boots_7")->wear();
	carry_object(__DIR__"../eq/cloth_pants_9")->wear();

	add_money("dollar",370);
}

void die()
{
	message_vision("$N�{�����e�s�F�@�n: OH~~ Check Out!!\n",this_object());
	::die();
}
