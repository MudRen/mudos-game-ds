#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�v�ڧJ",({"spock lin","spock","lin"}) );
	set("long",@LONG
�L�O�d��������`�x�v�A�M���t�d�V�m�d�����s�i�F���C
LONG);
	set("age",28);
	set("title",HIY"�a����"NOR);
	set("level",18);
	set("race","human");
	set("evil",-10);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�ڥثe���b�M�ߩ���ǰV�m�A�ڪ������O http://bbs.csmc.edu.tw/spock/�C");
	setup();

	carry_object(__DIR__"../wp/iron_hammer_10")->wield();
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_pants_8")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	add_money("dollar",1430);
}

void die()
{
	message_vision("$N�{�����e��: �����O��������!!\n",this_object());
	::die();
}
