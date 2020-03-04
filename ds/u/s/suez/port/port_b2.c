#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","地下水道");
	set("long",@LONG
幾隻蝙蝠被光一照就啪啦啪啦的飛了起來，富麗堂皇的設計讓這陰暗
的地底增添了些許詭異的氣氛，水滴落的聲音不停地迴盪著，自己的腳步
聲也在空氣中來回盤旋，讓人感覺好像有什麼東西在黑暗中窺視著你。
LONG 
);	
	set("light",0);
	set("exits",([
	    "north":__DIR__"port_b1",
	    "east":__DIR__"port_b4",
	    "south":__DIR__"port_b3"
		]));
	set("world","world1");
	set("objects",([
	    __DIR__"npc/bat":2,
		]));

	setup();

}
int valid_leave(object me, string dir)
{
	int temp = me->query_temp("police");
	if( me->query_temp("police_area")==1 && userp(me)) 
	{	
		temp++;
		me->set_temp("police",temp);
	}
        return ::valid_leave(me, dir);
}
