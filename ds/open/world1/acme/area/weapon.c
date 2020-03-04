// Room: /u/a/acme/area/weapon.c

inherit ROOM;

void create()
{
	set("short", "打鐵舖");
     set("light",1);
	set("long", @LONG
這裡是一間小小的打鐵鋪，鐵匠拿著打鐵工具在火爐旁敲敲打打的，
火爐映出你的影子在牆上一晃一晃的，你感覺到這裡出奇的熱，全身汗水
淋漓。往西則可出打鐵鋪。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"plaza2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/smith.c" : 1,
]));
set("room_type","sell");        //商店(只能買東西)
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
