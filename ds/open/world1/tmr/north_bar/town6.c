// Room: /open/world1/tmr/north_bar/town6.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
�u���o�঳���������H�s�A���Ʀb�j���e�����ۨV���C�]
���o�̬O������H�N���ꪺ�a�ϡA�����۷��e���A���̪���
���N�a�o�����ߤ@�����ͬ��A��ַ|���}���������C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town5",
  "east" : __DIR__"town13",
  "north" : __DIR__"town7",
  "west" : __DIR__"town12",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
