#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��Z���J�f");
	set("long", @long
�A����o�̫�o�{�o�̤H�s�H���A��ӳo�̥��O��Z�����J�f�A
�@���Q�ѥ[��Z���H�h���b�m�۳��W�C�t�~�A�A�]�o�{�o�̦��@��
�n���j���i�ܪ��ݥߵۡC

	���O�@:�@[sign]�@�@�@�@�@�@�ѥ[����

long);
	set("light", 1);
	set("exits", ([
		"west" : "/open/world1/cominging/area/hippodrome",
	]));

	set("objects", ([
		__DIR__"obj/record" : 1,
	]));

	setup();
}

int start_game()
{
	object *obs;

	obs = all_inventory(this_object());

	foreach(object me in obs)
	{
		MATCH_D->enter(me);
	}

	return 1;
}
