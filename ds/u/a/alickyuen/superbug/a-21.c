// Room: /u/s/superbug/train/a-21.c

inherit ROOM;

void create()
{
	set("short", "����Z����");
	set("long", @LONG
�o�̬O�@���Z�����A��W���ۦU���U�˪��Z���A�O�A�P��@�}���Ἲ
�áAť���o�̱M��ǥ����W�R���쪺�Z���A�]�\�A�i�H���@�Ǳj�O���Z
���A�d�i�e���ۤ@�Ӹ��Y�鸣���k�l�A���G�O�o������C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"a-14.c",
]));
set("objects", ([
__DIR__"npc/seller5.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
