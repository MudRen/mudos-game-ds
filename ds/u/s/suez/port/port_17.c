#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","第二碼頭");
	set("long",@LONG
這裡是薩爾薩斯第二碼頭，因為薩爾薩斯原來的港口已經超過負荷，
後來就由商人出資建造了第二碼頭，也因為如此，第二碼頭除了貿易貨船
以外並不接駁其他船隻，可以算是商人集團的私有港口。你可以看見四周
堆滿了各式各樣的貨物。
LONG 
);
	set("exits",([
	    "east":__DIR__"port_18",
	    "west":__DIR__"port_16",
		]));
	set("objects",([
	    __DIR__"npc/waterman":3,
	    __DIR__"npc/business_wm":1,
		]));

	set("world","world1");
	set("outdoor","land");

	setup();

}
int valid_leave(object me, string dir)
{
	int temp = me->query_temp("police");
        if( (dir=="west") && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
	if( me->query_temp("police_area") == 2 && userp(me)) 
	{	
		temp++;
		me->set_temp("police",temp);
	}

        return ::valid_leave(me, dir);
}
