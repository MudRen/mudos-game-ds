// Room: /open/world1/acme/area/f4.c

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
在這野林中，竟出現了這處一樹未生之地，在北邊有個山洞，似
乎是野獸的巢穴，然而地上卻片片血跡，氣氛十分詭譎。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"f3",
  "north" : __DIR__"f5",
]));
     set("outdoors","land");
set("objects", ([ 
  __DIR__"npc/bandit" : 3,
  __DIR__"npc/k_bandit" : 1,
]) );

	setup();
	replace_program(ROOM);
}
