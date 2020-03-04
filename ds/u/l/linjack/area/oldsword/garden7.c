#include <room.h>
inherit ROOM;
void create()
{
 set("short","屋頂花園");
 set("long",@LONG
這邊就是向雲堂正聽上方美麗的屋頂花園, 隔一道牆就到
休息室之中了, 不過休息室中沒有窗戶, 所以你也不能從這邊
進到屋子裡. 你可以看到這裡一片都長滿了青黃色的花朵, 有
寫淡藍色的果實.
LONG
    );
 set("exits",([ "east":__DIR__"garden3",
               "north":__DIR__"garden4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
