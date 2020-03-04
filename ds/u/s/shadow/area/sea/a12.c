/**
 * Shadow's area [�򩳥@�� - �򩳺ʨc���Y - a12]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"�򩳺ʨc���Y"NOR);
	set("long",
"�ʨc�����b�o�̨�F���Y�A�|�P�\\���F�U���U�˪��ï]�P���ߡA\n"
"�e��N�O�ʸT�Ǫ����f�A�J�f���ۤ@���b��Ϊ�"HIY"�p��"NOR"�A�A���յ۶i�J\n"
"�ʸT�ǡA�M�Ӫ��e���G�Q�����ɵ����A���o����ӤJ�C\n"
	);
	set("light", 1);
	set("no_clean_up", 0);
	set("exits",([
		"south" : __DIR__"a10",
		"west" : __DIR__"a11",
	]));
	set("item_desc", ([
		"�p��" : "�@���b��Ϊ����A���W����ӧΪ��_�Ǫ��}�A�ݰ_�ӫܹ��O�_�ͤ�(hole)�C\n",
		"hole" : "��Ӭ}��(left hole, right hole)�C\n",
		"left hole" : "���߫����}�աA�i�H��J�_�ͬݬ�(put)�C\n",
		"right hole" : "�������}�աA�i�H��J�_�ͬݬ�(put)�C\n",
		]));

	setup();

}

void init()
{
	add_action("do_put", "put");
}

int do_put(string arg)
{
}
