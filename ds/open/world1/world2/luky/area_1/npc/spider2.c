#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��j��", ({"dark spider","spider"}) );
	set("long", "�@���¦⪺�j�j��A�o�ػj�藍�����ӬO�a�r�������y���C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�e��", "�ᨬ", "����" })); //���𳡦�
	set("verbs", ({ "bite","claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 10);
	set("level",19);
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
	
	message_vision(HIW"$N���X�r�����$n�@�}�ër�A"NOR,me,victim);
	if(hitrole > 100)
	{
		victim->apply_condition("posion", victim->query_condition("posion")+3);
		message_vision(HIW"$n�{�����ΦӳQ�r���A�y��o���C\n"NOR,me,victim);
		victim->receive_damage("hp",20+random(20),me);
		return 1;
	}
	else message_vision(HIW"���Q$n��ĵ���{�F�L�h�C\n"NOR,me,victim);
	return 0;
}
