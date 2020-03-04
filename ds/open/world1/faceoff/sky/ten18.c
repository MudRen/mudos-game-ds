// Room: /open/world1/faceoff/sky/ten18.c

inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�A���b���s����_�����D���W�A�o���D�����G�q���A�F�誺�@�y�T
�ΡA�o�y�T�Τ��P��@��A��o�S�O����o�A�]�\�O�]����b�̭����H����
���P��@��H�t�~�o���D������_�豵��@�y�e�j���˪L�A�]�N�O�������W
���u�_��j�˪L�v�C�ǻ��̭���ۭ��H�ת����]�A�٦���q�·t�۳N���F��
�v�@���C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"ten17",
  "northwest" : "/open/world1/tmr/north_forest/sn20",
  "east" : __DIR__"ten19",
]));
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
