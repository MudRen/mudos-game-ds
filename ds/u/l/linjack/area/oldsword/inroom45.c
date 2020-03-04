#include <room.h>
inherit ROOM;
void create()
{
 set("short","總管寢室");
 set("long",@LONG
你一走進來就聽到連綿不斷的算珠敲擊的聲音, 而且非常
迅速, 一看就知道是老練的總管在算帳. 沒錯, 這正是總管的
寢室, 你看到有個人坐在書桌前面努力的算錢, 已經滿頭白髮.
不過仔細一看, 他撥的算盤是個至少重達五斤的巨大銅算盤, 
但是他蒼勁的指力卻可以毫不費力的撥動它, 可見你眼前的是
個內功修為深厚的老者.
LONG
    );
 set("exits",([ "north":__DIR__"inroom43",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
