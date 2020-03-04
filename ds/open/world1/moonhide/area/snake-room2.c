// Room: /open/world1/moonhide/area/snake-room2.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"snake-room4",
  "west" : __DIR__"snake-room5",
  "east" : __DIR__"snake-room1",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
