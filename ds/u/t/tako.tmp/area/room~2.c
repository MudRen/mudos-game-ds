#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞窟");
        set("long",@LONG
你走到洞窟裡面，只見周遭越來越暗，猛獸的的叫聲好像停止了，你心
裡暫時平靜了下來，你提心吊膽的繼續往內走，漸漸的你隱約聽到有人說
話的聲音你加快腳步的往內走，好像看到一隻野獸，但你心想:野獸怎麼會
說話ㄋ??
LONG      );
        set("exits", ([ /* sizeof() == 3 */
  "up" :"/u/t/tako/area/room~1.c",
  "north" :"/u/t/tako/area/room~3.c", 
  "west" :"/u/t/tako/area/room~6.c",  ]));
        set("outdoors","land");
    set("light",1);
        set("no_clean_up", 0);

        setup();

}

