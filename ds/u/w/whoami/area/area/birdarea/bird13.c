#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"天梟教"NOR"大門");

 set("long",@LONG
這裡是天梟教的大門, 是一個大石門, 門上刻著三個寫紅色的大
字《天梟教》, 左右各有一個梟的石像, 在門口有數個守衛, 看起來
都是練武之人, 你想寫這血紅色的字之人, 應該就在這裡了。
LONG
    );
 
 set("exits",(["east":__DIR__"bird14",
               "west":__DIR__"bird12",
     ]));
 set("objects",([__DIR__"npc/guard" : 3+random(3),
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           

