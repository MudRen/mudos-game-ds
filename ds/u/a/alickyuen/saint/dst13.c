// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠East[2;37;0m");
	set("long", @LONG
走出了那擠迫的人群，跑到來機械動物園附近。這個機械動物園是最
新開的，這亦是世界第一個能夠繁殖機械寵物的動物園，可算是一個大型
的計劃。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst12.c",
  "east" : __DIR__"door",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
