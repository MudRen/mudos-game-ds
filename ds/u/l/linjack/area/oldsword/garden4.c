#include <room.h>
inherit ROOM;
void create()
{
 set("short","屋頂花園");
 set("long",@LONG
這邊就是向雲堂正聽上方美麗的屋頂花園, 你可以看到
有兩三名園丁對你似乎不甚好感, 還是快點離開的好. 這邊
種了一些花花綠綠的植物, 沒有幾種是你認識的, 地上有一
些看起來像茶樹的灌木叢.
LONG
    );
 set("exits",(["north":__DIR__"garden8",
                "east":__DIR__"inroom8",
               "south":__DIR__"garden7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
