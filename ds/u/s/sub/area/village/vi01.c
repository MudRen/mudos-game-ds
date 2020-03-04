// Room: /u/s/sub/area/village/vi01.c

inherit ROOM;

void create()
{
	set("short", "小徑");
	set("long", @LONG
一條由動物所走出來的小徑，兩旁雜草叢生，地上凹凸不平，非常地
難走。草叢裡不時傳來各式各樣的昆蟲鳴叫聲，使得這個地方有一種說不
出來的荒涼。小徑向東北方延伸，不知通往何處。吸南方可以通往一處峭
壁。
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tree4",
  "northeast" : __DIR__"vi02",
]));

	setup();
	replace_program(ROOM);
}
