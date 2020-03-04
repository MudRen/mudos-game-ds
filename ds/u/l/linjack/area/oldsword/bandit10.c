#include <room.h>
inherit ROOM;
void create()
{
 set("short","山寨入口");
 set("long",@LONG
你仔細的看了四周的地理, 明白的顯示了這一定是個山寨, 
而且裡面住的人絕對不是什麼好料子. 可是你眼前所見卻沒有
營火, 也沒有土匪四處巡邏, 到底是怎麼回事? 你應該去弄個
明白.
LONG
    );
 set("exits",([ "north":__DIR__"b_inside1",
                "south":__DIR__"bandit9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}