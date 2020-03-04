// Room: /open/world1/moonhide/area/snake-room3.c

inherit ROOM;

void create()
{
	set("short", "���}��");
	set("long", @LONG
�u���}���ɬO������@���A�q�}�~�u�j�j�Ӷi�ǳ\����A��
�����H���⤣�������A���H�����C�q�}���`���_�ǨӨF�F�����T�A
���ߪ��G������_�ǥX�ӡC
LONG
	);
	set("current_light", 4);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"snake1" : 3,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"snake-room1",
  "east" : __DIR__"snake-room6",
]));

	setup();
	replace_program(ROOM);
}
