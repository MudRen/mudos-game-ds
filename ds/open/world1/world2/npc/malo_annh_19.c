#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�w�Ѥj",({"admin annihilator","annihilator","admin"}) );
	set("long",@LONG
�L�O�d�������Ѥj�A���d�ڪ��\�Ҥw�g�F�쯫���������ҬɤF�C
LONG);
	set("age",29);
	set("title",HIY"�d�ڱФ�"NOR);
	set("level",19);
	set("race","human");
	set("evil",10);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�ڥ��b�i��Neolith�p���A�A�i�H�W���Ӭݬ� http://es2.muds.net/�C");
	setup();
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10")->wield();
	carry_object(__DIR__"../eq/cloth_walkshoes_6")->wear();
	carry_object(__DIR__"../eq/cloth_pants_8")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	add_money("dollar",1290);
}

void die()
{
	message_vision("$N�{�����e��: �����ڬݧA�̥H���٦��S���d�ڥi�H��!!\n",this_object());
	::die();
}
