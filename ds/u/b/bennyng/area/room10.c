// Room: /u/b/bennyng/area/room10.c

inherit ROOM;

void create()
{
	set("short", "�����c");
	set("long", @LONG
�|�P���G�F�����᪺�խ��D�O�A�p�J�P�ү볳�K�D�n�q�L�����c�A�N
�����ѨM���e�������c�u�@�̡С������y�����t���h�D���_�N�O�q���Ь�
�j�����ߤ@�q�D�D
LONG
	);
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room11",
  "west" : __DIR__"room12",
  "south" : __DIR__"room13",
  "north" : __DIR__"room9",
]));
        set("objects", ([
  __DIR__"npc/Pisces.c":1,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
