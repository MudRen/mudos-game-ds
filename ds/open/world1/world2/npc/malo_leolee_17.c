inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("����t",({"leo lee","leo","lee"}) );
	set("long",@LONG
�@�ӳդh�Z�ǥ͡A����O�����s���n��M��k�B�͡A���b�ާ\���q�C
LONG);
	set("age",26);
	set("level",17);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�ޡA�ڦb�ۺq�Ф��n���ܡC");
	setup();

	carry_object(__DIR__"../eq/cloth_clothes_8")->wear();
	carry_object(__DIR__"../eq/cloth_boots_7")->wear();
	carry_object(__DIR__"../eq/cloth_pants_9")->wear();

	add_money("dollar",540);
}

void init()
{
	object ob = this_player();
	::init();
	if(this_object()->is_fighting()) return;
	if(!this_object()->visible(ob)) return;
		call_out("greeting",1,ob);
	return;
}

void greeting(object ppl)
{
	if(!ppl) return;
	if(environment(ppl)==environment(this_object()))
	{
		if(random(2)) command("sing ���ڤ@���R�Ӱ�");
		else command("sing ���n�ӡ㦾�d�ڪ���");
	}
	return;
}

void die()
{
	message_vision("$N�{�����e�s�F�@�n: I Will Be Back!!\n",this_object());
	::die();
}
