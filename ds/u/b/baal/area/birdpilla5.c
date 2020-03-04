#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"山洞內"NOR);

 set("long",@LONG
現在連頭頂上的光亮都消失的一乾二淨了, 你發出一聲絕望的嘆息, 
跌坐在石地上『完了, 一切都完了, 我將會埋屍在此, 消失在世上中, 永
遠消失在人們的記憶中... 』你心絕望的吶喊著, 你的眼淚噗囌囌的流下
, 滴在粗糙的石地上, 突然, 你在不遠的轉角處看到了一絲搖動的亮光, 
不知是不是幻像, 你心想：『去看看吧... 』
LONG
    );
 set("exits",([ "south":__DIR__"birdpilla4", 
                "north":__DIR__"birdpilla6",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

