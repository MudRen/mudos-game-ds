#include <ansi.h>
inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("���ݭ�",({"jao ei lon","jao","ei","lon"}) );
	set("long",@LONG
�@�Ӥp�Y�U�����Щx�o���b�o�̪F�i��檺�C
LONG);
	set("age",32);
	set("level",15);
	set("race","human");
            set("master","hack");
	set("evil",-15);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�K�A�u�n�w���u�v�ڴN���|�����A�C");
               set("nickname",HIG"�T�������Щx"NOR);
setup();

	add_money("dollar",240);
 }