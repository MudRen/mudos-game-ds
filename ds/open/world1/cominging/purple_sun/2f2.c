// �����s�ĤG�h

inherit ROOM;

void create()
{
	set("short", "�����s");
	set("long", @LONG
�o�̬O�����s���p���W���n�䪺�a��A�A�٥i�H�����ݨ�ɿ����x
�����ΡA������W�H�骺�ˤl�A���F�O���W����s���A�ө���h�O���s
�U���h�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"2f3.c",
  "northwest" : __DIR__"2f1.c",
]));
	set("objects", ([
  __DIR__"npc/tiger" : 1,
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
