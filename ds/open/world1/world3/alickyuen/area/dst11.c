// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠East[2;37;0m");
	set("long", @LONG
這裡北面是一間大酒店，那裡的設備非常完善，亦是很多人渡假住的
地方。而前面那間店舖依然人山人海，看來應該是一間賣食物的店，你想
可能那裡有好的東西，就想衝過去湊湊熱鬧。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"inn.c",
  "west" : __DIR__"dst6.c",
  "east" : __DIR__"dst12.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
