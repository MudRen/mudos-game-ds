#include <room.h>
inherit ROOM;
void create()
{
 set("short","密林");
 set("long",@LONG
這裡的密林籠罩了你的整個視野, 四周圍樹葉搖曳和風沙吹動
的聲音擾亂了你的聽覺, 你彷彿在一個完全沒有方位的地方. 本以
為可以用上下坡來判斷你的方向, 誰知道這裡的地竟是個平台! 真
不知道向雲堂會建在哪個恐怖的地方.
LONG
    );
 set("exits",([ "west":__DIR__"forest2",
                "south":__DIR__"forest6",
                "east":__DIR__"forest7",
                "north":__DIR__"forest9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}