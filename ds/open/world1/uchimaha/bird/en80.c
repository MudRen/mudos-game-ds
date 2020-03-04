#include <room.h>
inherit ROOM;
void create()
{
 set("short","千年古木上");
 set("long",@LONG
你現在站在千年古木的樹枝上, 雖然說是樹枝, 但卻
是和平常的樹木的樹幹差不多粗, 在這樹枝上有一隻巨大
的鳥類正在尋找食物, 牠看來肚子很餓的樣子.

LONG
    );
 
 set("exits",(["down":__DIR__"en70",
              ]));
 set("objects",([__DIR__"npc/godbird" : 1,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
