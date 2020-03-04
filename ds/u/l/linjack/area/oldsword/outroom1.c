#include <room.h>
inherit ROOM;
void create()
{
 set("short","向雲堂內苑大門");
 set("long",@LONG
這邊就是向雲堂內苑的大門, 十分宏偉壯觀, 上面的屋筵
龍飛鳳舞, 不知道是出自那家雕刻家的名作, 門上兩個門神畫
得栩栩如生, 門前有四五名侍衛畢恭畢敬的向你行禮請安, 個
個都十分威武, 看來這向雲堂果真不簡單.
LONG
    );
 set("exits",([ "north":__DIR__"inroom18",
                "south":__DIR__"outroom4",
                 "west":__DIR__"outroom2",
                 "east":__DIR__"outroom3",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}