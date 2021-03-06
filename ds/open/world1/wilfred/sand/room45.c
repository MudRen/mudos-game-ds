// Room: /open/world1/wilfred/sand/room45.c

inherit ROOM;

void create()
{
	set("short", "磐龍城-護城大橋口");
	set("long", @LONG
這是磐龍城的護城大橋，只見一條長約百來尺，寬約十尺的大橋
橫跨了護城河與城門口之間。磐龍城為軍事戰略要點，往北為大漠草
原，居住著半人半虎的民族，生性好戰，數十年來一直想要往南侵犯
，好在有天下第一勁旅少帥軍據守磐龍城，才保障全天下的平安。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room44",
  "north" : "/open/world1/tmr/dragoncity/bridge1",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
