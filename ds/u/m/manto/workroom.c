// Room: /u/m/manto/workroom.c

inherit ROOM;

void create()
{
	set("short", "[1;33m�]Ţ[0m");
	set("long", @LONG

�o�̨�B�O�����A�A�i�j�����@�ݡA��ӳo�̬O�]Ţ�̭�...

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 5 */
  "start" : "/open/world1/tmr/area/hotel",
  "east" : "/open/world1/manto/dragon_festival/room02",
  "wiz" : "/d/wiz/hall1",
  "newsky"  :  "/open/world1/manto/sky2_1f/map_7_13",
  "sky" : "/open/world1/acme/area/sky/room35",
]));
	set("no_clean_up", 0);

	setup();
     call_other("/obj/board/manto_b", "???");
	replace_program(ROOM);
}
