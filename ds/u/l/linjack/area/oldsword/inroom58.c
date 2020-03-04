#include <room.h>
inherit ROOM;
void create()
{
 set("short","天橋中央");
 set("long",@LONG
經過了練功塔的天橋, 你來到了這裡的天橋中央, 左右
有一個平臺可以走, 但是沒有路可以再往前走下去. 地板上
似乎可以看出一個方形圖騰, 不知道是個什麼東西, 看起來
滿詭異的.
LONG
    );
 set("exits",(["east":__DIR__"inroom59",
               "west":__DIR__"inroom60",
               "south":__DIR__"inroom57",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
