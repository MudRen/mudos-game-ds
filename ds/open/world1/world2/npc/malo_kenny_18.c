#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�֥�",({"kenny hsieh","kenny","hsieh"}) );
	set("long",@LONG
�L�O�d�������]�F�U�ݡA�M���t�d�����d���������䥭�šC
LONG);
	set("age",28);
	set("title",HIY"�d�ڶ¤�"NOR);
	set("level",18);
	set("race","human");
	set("evil",-10);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","��..�̪񴺮�u�t�C");
	setup();

	carry_object(__DIR__"../wp/iron_dagger_10")->wield();
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_pants_8")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	add_money("dollar",2250);
}

void die()
{
	message_vision("$N�{�����e��: ���G�M���O�U�઺!!\n",this_object());
	::die();
}
