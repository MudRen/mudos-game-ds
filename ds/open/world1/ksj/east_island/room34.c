#include <room.h>
inherit ROOM;

void create()
{
 set("short","河堤");
 set("long",@LONG
這裡是一座高高的土堤，土堤上鋪著大小不一的石塊，由於裴伊
川每年都會犯濫，村民為了保護村莊及農田，所以築了這道土堤，土
堤下是澄澈的裴伊川，很難想像河水湍急兇猛的模樣。
LONG);
   set("exits",([ 
       "south":__DIR__"room33",
       "north":__DIR__"room35",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            

void reset()
{
 if( !random(5) )
 {
   set("objects",([
   __DIR__"npc/ningyo":1,
   ]));
 }
        ::reset();
}
