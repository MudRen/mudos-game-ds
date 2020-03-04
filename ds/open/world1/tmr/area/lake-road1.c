// Room: /u/t/tmr/area/lake-road1.c

inherit ROOM;

void create()
{
        set("short", "湖邊小路");
        set("long", @LONG
一條沿著湖邊的小路，為用朝天湖的河床石塊所鋪設而成的路，赤腳
踩踏上去的感覺聽說不錯哦。由此向北方望去，可隱約看到朝天湖的東半
部，只見湖中小舟蕩槳，採菱歌聲泠泠，也有賞蓮遊人，畫船簫管鱗集；
上下一色，景致令人嘆為觀止。往東為一條白石階
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	   "eastup" : __DIR__"lake-road2",
           "northwest" : __DIR__"day_lake",
	]));
	set("outdoors","land");
        set("no_clean_up", 0);
	set("no_map",1);
        setup();
        replace_program(ROOM);
}
