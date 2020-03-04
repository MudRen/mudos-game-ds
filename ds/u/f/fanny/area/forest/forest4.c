// Room: /u/f/fanny/area/forest/forest4.c

inherit ROOM;

void create()
{
    set("short", "山洞");
    set("long", @LONG
進到這裡，身上的毛髮全都不自禁的豎立了起來，你不自覺的擺
出自己最強的身形來保護自己，一種死亡的氣息正在侵蝕著你繼續待
在這裡的意志。
LONG
        );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"forest3.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/u/f/fanny/area/npc/tiger" : 1,
  "/u/f/fanny/area/npc/tigress" : 1,
  "/u/f/fanny/area/npc/cutetiger" : 3,
]));
	setup();
	replace_program(ROOM);
}
