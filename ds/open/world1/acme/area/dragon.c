// Room: /u/a/acme/test/dragon.c

inherit ROOM;

void create()
{
	set("short", "�x�s�W");
	set("long", @LONG
�o�̬O���ۤ��W�A�|�P�Ūſ����A���O���B�����L��A�Q���j�ǡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"l",
]));
set("objects",([
    __DIR__"npc/devil" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
