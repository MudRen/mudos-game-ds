// Room: /open/world1/tmr/area/wa7.c

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
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jellyfish" : 4,
]));
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"wa1",
  "down" : __DIR__"wa8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
