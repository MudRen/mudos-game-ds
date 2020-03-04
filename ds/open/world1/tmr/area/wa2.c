// Room: /open/world1/tmr/area/wa2.c

inherit ROOM;

void create()
{
	set("short", "�¤Ѵ�Ф���");
	set("long", @LONG
�A���b�¤Ѵ�̡A�u���|�g���O�C�Ť@���A�i�M���ݨ줣�֪��ͪ��A
��̴���ˤ]���鳰�a�F�u�O�P�򴺦�j���@�P�A�ꤣ���F�n��_�U�O�q
�V���C
LONG
	);
	set("world", "past");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fish" : 4,
  __DIR__"npc/bfish" : 1,
]));
	set("light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wa3",
  "north" : __DIR__"wa1",
  "eastup" : __DIR__"wa4",
  "east" : __DIR__"wa6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
