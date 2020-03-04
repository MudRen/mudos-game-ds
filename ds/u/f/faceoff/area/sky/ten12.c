#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","村道");
 set("long",@LONG
這裡是位於村中的道路，你可以看見北邊有一座快散掉
的茅屋，它在屋前掛了一面隨風飄蕩的木牌，上面寫了個「
藥」字，而南邊則是一家看起來快倒閉的客棧，不知道在這
裡的客棧要如何維生？至於西邊則是一個廣場，也是村子裡
最繁榮的地方了.
LONG
    );
 set("exits",([   "north":__DIR__"ten13",
               "south":__DIR__"ten15",
               "west":__DIR__"ten17",
               "east":__DIR__"ten11",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

