#include <room.h>
inherit ROOM;
void create()
{
 set("short","死路");
 set("long",@LONG
你打破了北邊的牆, 發現這裡又是一個死路了, 你簡直是茫
無頭緒. 或許你應該好好的觀察觀察這裡, 說不定有什麼發現喔!
LONG
    );
 set("exits",([ "east":__DIR__"secret6_1",
                "north":__DIR__"secret1_5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
