inherit ROOM;

void create()
{
	set("short", "森林入口");
	set("long", @LONG
這裡是步靈城西方的森林入口，江湖上都說要到疾風門需經過這一
條羊腸小徑，似乎並不簡單，在這裡的樹木底下都有一團團的紫蘇玉蘭
花，不過似乎都還沒開花的樣子，往西邊是一條小路，似乎並不大，而
東邊則是返回步靈城的路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"fgo2.c",
  "east" : __DIR__"fgo.c",
]));
	set("objects",([
  __DIR__"npc/obj/wtree.c" : random(4),
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
