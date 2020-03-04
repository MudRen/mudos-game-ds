// Room: /open/world1/moonhide/area/snake-room.c

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
        set("objects",([
        __DIR__"snake1" : 2 + random(2),
]));
	set("exits", ([ /* sizeof() == 3 */
  "out" : "/open/world1/cominging/area/fgo2.c",
  "north" : __DIR__"snake-room1",
  "west" : __DIR__"snake-room4",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
