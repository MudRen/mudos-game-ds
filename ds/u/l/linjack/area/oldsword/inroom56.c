#include <room.h>
inherit ROOM;
void create()
{
 set("short","練功\塔");
 set("long",@LONG
原來這邊就是平時護衛和弟子們切磋武技的地方, 有一大
櫃的兵器架在這裡, 基本兵器種類應有盡有, 或許你可以和他
們磨磨刀. 這兒風景不錯, 北邊還有條天橋可以走過去.
LONG
    );
 set("exits",(["north":__DIR__"inroom57",
                "down":__DIR__"inroom51",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
