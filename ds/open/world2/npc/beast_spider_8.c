#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�H���j��", ({"face pattern spider","spider"}) );
	set("long", "�@���I�����ۤH���᯾�����j�j��A��������઺���ۧA�C\n");
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�e��", "�ᨬ", "����" })); //���𳡦�
	set("verbs", ({ "bite","claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 2);
	set("level",8);
	set_temp("apply/hit",-20);      //�z�ƩR���v
//	set_temp("fly",1);
//	set("chat_chance",1);
//	set("chat_msg",({
//		(: this_object(), "random_move" :),
//	}));

	setup();
}
int special_attack(object me,object victim,int hitrole)
{
	if(!me || !victim) return 0;
	if(random(5)) return 0;
	
	message_vision(HIW"$N��$n�R�X�@���H�G�A"NOR,me,victim);
	if(hitrole > 100)
	{
		message_vision(HIW"$n�{�����ΦӳQ�H�G�Q���A�ʼu���o�C\n"NOR,me,victim);
		victim->start_busy(2);
		return 1;
	}
	else message_vision(HIW"���Q$n��ĵ���{�F�L�h�C\n"NOR,me,victim);
	return 0;
}
