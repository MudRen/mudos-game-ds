// �����s�ĥ|�h
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�p�Ŧa�W");
	set("long", @LONG
�o�O�@�Ӥp�Ŧa�A�b�o�̦��ǰʪ��b�樫�A�b�A���|�P�O���p�Ŧa
�A�n�p�ߤ@�I�A���M�N�|�L�U�s�U�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"4f5.c",
  "west" : __DIR__"4f4.c",
  "south" : __DIR__"4f1.c",
  "east" : __DIR__"4f3.c",
]));
	set("objects", ([
  __DIR__"npc/leopard" : 3
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

int dish_up()
{
	object dish = new(__DIR__"npc/obj/dish.c");
	dish->move(this_object());
	message_vision(HIR"�o�̬�M�@�}����, ��M�@�ӥ۽L�q�a�W�w�w���... \n"NOR, dish);
	return 1;
}

void start_animal_war(object me, object c)
{
	string file, str;
	file = __DIR__"war.log";
	str = sprintf("%s(%s) �� %s �}�ҤF Purple Sun's Animal's War �C\n", me->query("name"),geteuid(me),ctime(time()));
	write_file(file, str);
	destruct(c);
	message("world:world1:vision", 
		HIW" �����s�W�u���@�D�D���ե��g�X��� \n" NOR
		HIC"\n\n �����s�W��M�@�n�Ѫ���S�K�K \n\n"NOR
		HIR"���۵����s�W��M�@�}���T�M�����~�b�꯫�����l�U�M�@�ӭӪ����k�X�}�ޡM�}�l�v�h�F�I�I\n\n\n"NOR,users());
	call_out("end_animal_war", 240);
}

void end_animal_war()
{
	string file, str;
	object animal = find_living("animal-war-object");

	if( objectp(animal) )
	{
		if( !environment(animal) ) destruct(animal);
		call_out("end_animal_war", 60 );
		return;
	}
	else {
		message("world:world1:vision",
	HIM"\n\n       �u�������s�@�U�lŢ�n�b�@�D�����U�K \n\n"NOR
	HIR"       �꯫�¤Ѫ��S�F�X�}�l�M���G�ߦ����̪��ˤl�K�K \n\n"NOR
	HIY"�� "HIG" �����s�S�^�_��F���R \n\n"NOR, users());
		file = __DIR__"war.log";
		str = sprintf("%s Purple Sun's Animal's War �����C\n", ctime(time()));
		write_file(file, str);
		this_object()->delete("war_start");
		return;
	}
}