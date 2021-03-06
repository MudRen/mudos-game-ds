// Room: /u/l/lestia/area/sn2.c

inherit ROOM;

void create()
{
 set("short", "北方大森林");
	set("long", @LONG
走到這裡，你發現滿地散落的楓樹落葉，彷彿紅黃交織而成的地毯，你
不禁懷疑自己在夢境中來到了童話世界。茂密的楓樹林阻隔了外界傳來的光
線，僅有的月光下散發星星一般淒迷的光芒，使你全然不覺黑夜與白晝的交
替。
LONG
	);
	set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"npc/pan_statue" : 1,
        ]));

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sn3",
  "north" : __DIR__"sn1",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
