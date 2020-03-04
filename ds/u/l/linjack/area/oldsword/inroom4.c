#include <room.h>
inherit ROOM;
void create()
{
 set("short","正廳");
 set("long",@LONG
你通過了一條長廊來到了這向雲堂的正廳之中, 只見中
央有一支大有頂天立地之勢的柱子, 上面紋龍刻鳳, 好不華
美. 整個正廳從此看去十分廣闊, 雖然現在向雲堂並沒有大
型宴會, 可是來做客的人倒還不少, 向雲堂像個觀光聖地.
LONG
    );
 set("exits",([
               "north":__DIR__"inroom62",
                "east":__DIR__"inroom63",
                "west":__DIR__"inroom64",
               "south":__DIR__"inroom7",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
