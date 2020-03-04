#include <room.h>
inherit ROOM;
void create()
{
 set("short","皇城景隆門前");
 set("long",@LONG
才來到這, 就發現人山人海, 原來這兒就是聖宗上國的皇城
四大城門之中, 偏東北邊的景隆門前, 這兒是進城的必經之路,
因此雖尚未到關卡, 卻已經有不少巡邏官兵在此嚴陣以待, 如果
想在皇城作亂, 恐怕就找錯地方囉!
LONG
    );
 set("exits",([ "southwest":__DIR__"nedoor",
                "northeast":__DIR__"market3"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}