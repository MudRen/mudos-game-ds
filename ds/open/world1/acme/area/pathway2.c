// Room: /u/a/acme/area/pathway2.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這是一條位於天城北方的小路，這裡的路往東北延伸而去，可通往天
池，南邊是往天城最熱鬧的市集。這條小路令人感覺十分清新，小路的兩
旁生長著高大的老松樹，不時傳來小鳥的鳴叫聲。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ndoor.c",
  "south" : __DIR__"pathway1",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
