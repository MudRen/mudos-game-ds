// Room: /u/s/sonicct/area/shop6.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�o�̺شӪ���Q���}�G�A�A�u�Q�K�U�@����Ӱe���A���R�H�A�i�O�A
���R�H�O�֩O�H�b�o�̪��n���i�H���X���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"road16",
  "south" : __DIR__"road15",
]));
		 set("objects",([
  __DIR__"npc/butterfly":3,
 ]));

	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
