#include <ansi.h>
inherit NPC;
void create()
{
	set_name("���C�C",({"grandma wang","wang","grandma"}) );
	set("long",@LONG
���C�C���~�w�g�C�Q���l�F�A���L�٬O�믫���������w��B����l�C
LONG);
	set("age",72);
	set("title","���s���");
	set("level",18);
	set("race","human");
	set("gender","�k��");
	set("evil",-10);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�{�b���~���H�u���Y���F�W�C");
	setup();

	carry_object(__DIR__"../eq/cloth_boots_5")->wear();
	carry_object(__DIR__"../eq/cloth_skirt_6")->wear();
	carry_object(__DIR__"../eq/cloth_robe_12")->wear();
	add_money("dollar",430);
}
int talk_action(object me)	
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 command("smile "+me->query("id") );
 command("say "+@TALK_1
  ť���������j�������W�����F���ڡA�i�H�ޥX�ͪ��餺�����C
�Ʊ�o���t���۵M�O�q���n���J���c�}��̡C
TALK_1
 );
 //book->add_quests_note("SadSworder","�y�N�M�l�z�O�@�ط����@�P���s�A���߱��{�e�A�άO�u�����ҧx�v���H���̷R�C");
 return 1;
}

