#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","中心街");
        set("long",@LONG
從薩爾薩斯港往北的這個地方，有幾間比較氣派的房子，是薩爾薩斯
人裡面比較有地位者居住的地方，也因此得到中心街的名稱，雖然實際上
這裡位於薩爾薩斯的最北邊。東邊則是薩爾薩斯名義上的行政中心。
LONG 
);
        set("exits",([
            "east":__DIR__"port_09",
            "west":__DIR__"port_03",
            "south":__DIR__"port_07",
                ]));
        set("objects",([
             __DIR__"npc/business_wm":1,
            __DIR__"npc/business_mn":1,
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();

}
int valid_leave(object me, string dir)
{
       if( (dir=="west" || dir=="east" )&& !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}


