// Room: /u/b/bennyng/area/room37.c

inherit ROOM;

void create()
{
	set("short", "�_�V");
	set("long", @LONG
�o���_�V�N�O��~�s�y���s�P�s�Ϯy�����t���h��ù�ҥ�Ԫ��a��A
�N�O�]����ù���@�۸t�C�A��o���q�D�ܦ��_�V�A���i�ਫ�h�ﭱ�A�A�u
�����L�h�~�����|�~��e�i�D
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room38",
  "north" : __DIR__"room36",
]));
        set("objects", ([
  __DIR__"npc/Capricorn.c":1,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
