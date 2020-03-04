//charm

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("�X����",({"wind seal","seal"}) );
	set("long",@LONG
�@�i�D�h�Ψӧ@�k���šA�W�Y�β���g�F�Ʀ�Ť�A�r�̦涡�z�S
�ۤ@�Ѫk�O�C�q�`�o���ݩ��J�D�a���D�h���ũG�A�����Y���۷��k
�O�A�N�O�@��H�]����G�I�k�]charm�^�A�u�O�k�N�ĪG���j�C
LONG
	);
	set_weight(50);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","�i");
		set("value",500);
	}
	setup();
}

void init()
{
	add_action("do_charm","charm");
}

int do_charm(string arg)
{
	object me,tar,*enemy;
	int i,t,damage;

	me=this_player();
	if(!me->is_fighting() ) return notify_fail("�A�èS���b�԰����C\n");
	if(me->is_busy() ) return notify_fail("�A�����ۡA�S�ũ��k�I�G�C\n");

	enemy=me->query_enemy();
	t=sizeof(enemy);
	message_vision(
CYN "$N�I�U�@�i�X���šA�f�����ۻy�A�~�a���a�@�}�e���I�I\n" NOR
	,me);
	
	for (i=0;i<t;i++)
	{	
	if (i>2 ) continue;
	tar=enemy[i];
	damage=me->query_int();
	damage-=tar->query_shield()+tar->query_int();
	if (damage<=0) damage=1;
	if (damage>50) damage=50;

		if(tar->is_busy()
		   || random(tar->query_dex()+tar->query_int() ) < random(me->query_dex()+me->query_int() )  )
		{
		message_vision("�@�}�e���p�M�C��b$N���W�y���ƳB�ζˡC\n",tar);
		tar->receive_damge("hp",damage);
		COMBAT_D->report_status(tar);
		}

	}
	message_vision("\n$N��W���ũG�N���u�ѤU���u�F�C\n",me);
	destruct(this_object() );
	return 1;
}