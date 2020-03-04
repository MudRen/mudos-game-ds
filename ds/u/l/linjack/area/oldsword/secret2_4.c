#include <room.h>
inherit ROOM;
void create()
{
 set("short","死路");
 set("long",@LONG
你來到了一個死巷裡, 乍看之下什麼都沒有, 可是你若仔
細的觀察就會覺得你所踏之地是空心的, 一定是什麼密道或密
室所在之地, 而且你還能看到地上有一個石塊, 石塊中有一個
小孔, 看起來是要用鑰匙才能開啟這個秘門.
LONG
    );
 set("exits",([ "east":__DIR__"secret2_3",
                "down":__DIR__":secret2_6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
