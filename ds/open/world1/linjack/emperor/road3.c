#include <room.h>
inherit ROOM;
void create()
{
 set("short","道路上");
 set("long",@LONG
這整條路的行進方向是往偏西南而去, 但是路上人群稀少,
偶爾能看到幾個旅人經過已屬稀奇了. 附近有幾家商店都因為
太少人光顧而紛紛倒閉了. 西南不遠處望去, 似乎看到有些市
聲鼎沸的市集, 看來快到某個大城了.
LONG
    );
 set("exits",([ "east":__DIR__"road2",
                "southwest":__DIR__"road4",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}