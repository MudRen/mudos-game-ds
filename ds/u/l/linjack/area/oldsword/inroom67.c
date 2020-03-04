#include <room.h>
inherit ROOM;
void create()
{
 set("short","正廳");
 set("long",@LONG
這裡是正廳的左側, 由此可以通過一個走道是往左偏廳走的,
你看到有兩個守衛正看管著往右偏廳的路, 想要做些不法的事,
恐怕沒那麼容易. 另外, 這邊有三四位名醫在此高談闊論, 你
若有什麼病痛說不定可以找他們看一看.
LONG
    );
 set("exits",(["north":__DIR__"inroom69",
                "west":__DIR__"inroom6",
                "east":__DIR__"inroom62",
               "south":__DIR__"inroom64",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
