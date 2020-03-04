inherit ROOM;

void create()
{
	set("short", "步靈城旁");
	set("long", @LONG
這裡是步靈城的護城河旁邊，在這裡有許多的花草樹木，也有許多
的蝴蝶和昆蟲，而鳥兒們則在樹枝、樹葉上面吱吱喳喳的叫響，頗有些
許的幽閒感，在東邊是往步靈城裡面前進，而往西邊卻只有一條小徑可
以行走，似乎空間不大的樣子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"fgo1.c",
  "east" : __DIR__"river6.c",
]));
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}