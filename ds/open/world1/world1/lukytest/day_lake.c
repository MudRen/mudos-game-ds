// Room: /u/t/tmr/area/day_lake.c

inherit ROOM;

void create()
{
	set("short", "朝天湖");
	set("long", @LONG
朝天湖，又名荷花蕩，為此地赫赫有名的奇景。原在十幾年前只是個
景色平常的大湖，後來來了一個名叫秋先的老叟，於岸旁堆土作堤，廣植
桃柳，沿湖通插芙蓉，湖中種五色蓮花，盛開之日，滿湖錦雲爛熳，香氣
襲人，四時景致，言之不盡，隨即此湖聲名大噪，秋先也在湖旁建了個木
屋定居下來。							
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//  "northeast" : __DIR__"round1",
//  "southeast" : __DIR__"lake-road1",
//  "west" : __DIR__"square",
]));
set("objects",([
	__DIR__"../npc/fisher.c" : 2,
]) );

	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
