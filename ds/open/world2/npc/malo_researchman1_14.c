#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�d�w��",({"kenderwen"}) );
	set("long",@LONG
�L�O�������ΥͤƬ�s�Ǫ��S�����A��@�ɦU�a�����֦��S���O��
�ͪ��˥��C
LONG);
	set("age",34);
	set("title","�ͤƬ�s��");
	set("level",14);
	set("race","human");
	set("evil",-10);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","ť���o���񦳺ة_�S�����a����a���H�̩��B�C");
	setup();

	//carry_object(__DIR__"../wp/iron_dagger_10")->wield();
	carry_object(__DIR__"../eq/life_glasses")->wear();
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_gloves_3")->wear();
	carry_object(__DIR__"../eq/cloth_pants_8")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	add_money("dollar",950);
}
