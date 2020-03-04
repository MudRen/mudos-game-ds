#include <room.h>
inherit ROOM;
void create()
{
 set("short","正廳");
 set("long",@LONG
這裡是正廳的右側, 由此可以通過一個走道是往右偏廳走的,
你看到有兩個守衛正看管著往右偏廳的路, 想要做些不法的事,
恐怕沒那麼容易. 除此之外, 這邊有幾個練丹士正在聊天.
LONG
    );
 set("exits",(["north":__DIR__"inroom68",
                "west":__DIR__"inroom62",
                "east":__DIR__"inroom5",
               "south":__DIR__"inroom63",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
