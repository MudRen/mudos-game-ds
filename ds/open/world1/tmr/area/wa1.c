// Room: /u/t/tmr/area/wa1.c

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
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wa2",
  "up" : __DIR__"waroom",
  "north" : __DIR__"wa5.c",
  "down" : __DIR__"wa7.c",
]));
	set("light",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fish" : 4,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
