// Room: /u/t/tmr/area/wa3.c

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
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wa2",
  "up" : __DIR__"day_lake",
]));
	set("light",1);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/bfish" : 2,
  __DIR__"npc/fish" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
