#include <room.h>
inherit ROOM;
void create()
{
 set("short","屋頂花園");
 set("long",@LONG
這邊就是向雲堂正聽上方美麗的屋頂花園, 你可以看到
有許多老園丁正和細心的照顧花草, 並沒有注意到你的到來.
這邊種了一些花花綠綠的植物, 沒有幾種是你認識的, 這邊
你認得的植物是幾株山芋, 不過是紫色的. 北邊還有一塊地
是在山縫之中的, 但有守衛把守著.
LONG
    );
 set("exits",(["north":__DIR__"garden9",
                "east":__DIR__"garden5",
               "south":__DIR__"inroom8",
                "west":__DIR__"garden8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
