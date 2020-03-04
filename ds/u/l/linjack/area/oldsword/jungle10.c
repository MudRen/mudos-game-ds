#include <room.h>
inherit ROOM;
void create()
{
 set("short","平台之上");
 set("long",@LONG
離開了那個恐怖的沼澤, 你總算來到一塊比較高起的台地
上, 這邊果然有些玄妙的地方, 在草叢間似乎有幾顆發光的小
東西!!真是令你好奇, 那到底是什麼呢? 這邊比較亮了, 你可
以明顯的看到唯一的出路就是走出沼澤.
LONG
    );
 set("exits",([ "east":__DIR__"jungle9",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
