// Room: /u/t/truewind/Minetown/area/workerroom4.c

inherit ROOM;

void create()
{
	set("short", "工寮中");
	set("long", @LONG
工寮的牆壁上爬著一些奇怪的小蟲，沿著牆壁上的水跡四處爬行
。天花板跟地板周圍還遍佈著一些塑膠水管，看來是工寮的供水系統
。整個空間你只聽到水滴從天花板水管漏出來，滴到地板的聲音。這
裡的環境真是令人難以忍受。

LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("objects", ([ 
        __DIR__"npc/worker.c" :4 ,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"workerroom3",
]));

	setup();
	replace_program(ROOM);
}
