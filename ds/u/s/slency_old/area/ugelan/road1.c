// Room: /u/s/slency/area/ugelan/road1.c

inherit ROOM;

void create()
{
	set("short", "南城門口");
	set("long", @LONG
這裡是幽遮蘭城南城門的路口，路旁的房舍交錯雜處，看著周遭五
光十色的招牌景致，此城的富庶絕不在話下，這裡的街道相當乾淨整齊
，想來此城裡的法律必是相當嚴密的，也難怪此城能百年來一直屹立不
搖，身居偉大帝國的地位，往北是一間頗大旅店，東西橫貫著一條大街
。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road8",
  "south" : __DIR__"bigdoor",
  "east" : __DIR__"road2",
  "north" : __DIR__"inn",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
