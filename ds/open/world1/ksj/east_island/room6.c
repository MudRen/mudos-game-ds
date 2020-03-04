#include <room.h>
inherit ROOM;

void create()
{
 set("short","小路");
 set("long",@LONG
走到這邊是村莊跟漁村間的道路，離海岸有一段距離，海風微微
地吹來，兩旁的防風林上棲息著幾隻白鷺鷥，路邊長了許多耐旱的藤
類及雜草。
                ╭─╮              ╭─╮
                │  │              │  │                     
────────╯  │              │  ╰─────────
                    │              │
                    │              │
──────────╯              ╰───────────
LONG
    );
   set("exits",([ 
       "enter":__DIR__"room7",
       "northeast":__DIR__"room5",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
