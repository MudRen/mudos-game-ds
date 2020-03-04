#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","地下水道");
	set("long",@LONG
這裡就是薩爾薩斯的地下水道系統了，一道石梯往上延升到薩爾薩斯
廣場，被精心研磨的石塊堆砌成拱狀的結構，四周的牆壁則雕刻了各式
各樣人物像，踩在這裡的地面上就有如踩在碎冰上發出清脆的響聲，細
細的水流在水道中央緩緩的流動著，但這裡終究是個下水道，仍然有著
惡臭以及四處亂跑的老鼠。
LONG 
);	
	set("light",0);
	set("exits",([
	    "up":__DIR__"port_19",
	    "south":__DIR__"port_b2"
		]));
	set("world","world1");
	set("objects",([
	    __DIR__"npc/rat":3,
		]));

	setup();

}
int valid_leave(object me, string dir)
{
	int temp = me->query_temp("police");
	if(  me->query_temp("police_area")==1  && userp(me) && (dir != "up")) 
	{	
		temp++;
		me->set_temp("police",temp);
	}
        if( (dir=="up") && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
