#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","老鷹洞");

 set("long",@LONG
這裡是一個老鷹洞, 裡面只有四隻幼鷹在吱吱的叫著, 看樣
子是肚子餓了, 難怪沒看到老鷹, 原來是出去捕食了, 你環顧四
周, 都是樹枝和葉子, 地上還有些許的羽毛, 看來沒有什麼異狀
LONG);
 
 set("exits",(["out":__DIR__"bird4",
     ]));
 set("objects",([__DIR__"npc/eagle" : random(4)+2,
                 __DIR__"npc/eagle2" : random(2)+1,
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           

