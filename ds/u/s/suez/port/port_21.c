#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","尤拉大道");
        set("long",@LONG
一條筆直的大路從這裡往東西向延伸出去，這裡就是大商人尤拉所建
造的尤拉大道。因為這條路的建設，貨物的運輸更方便了，間接的也促進
了薩爾薩斯港本身的商業發展。愈來愈多人經由這條大道來到薩爾薩斯，
而在這裡南方的「凡琴斯島」旅社也成為這些人休息駐足的重要地點。
LONG 
);
        set("exits",([
            "west":__DIR__"port_20",
            "south":__DIR__"port_24",
            "east":__DIR__"port_22"
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();

}
int valid_leave(object me, string dir)
{
        if( (dir=="east"||dir=="south") && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}


