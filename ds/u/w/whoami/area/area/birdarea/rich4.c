#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","富宅長廊");
 set("long",@LONG
你來到了獵狐村首屈一指的富豪的家裡, 這裡的佈置和陳設
沒有一樣不是貴的嚇人的, 看來住在這的真的不是等閒之輩, 於
是你加快腳步向前走去, 希望能見到這的主人
LONG
    );
 
 set("exits",(["south":__DIR__"rich3",
               "north":__DIR__"rich5",
              ])); 
 setup();
}        

