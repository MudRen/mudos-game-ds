#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"山洞內"NOR);

 set("long",@LONG
你小心的來到這個陰暗, 潮濕, 又充滿霉味的地方, 『吱』的一聲,
一群小老鼠從你腳下竄出, 突然, 你四周引起一陣騷動, 一股濃厚的腐臭
味朝你襲來, 一團黑影如朝水般湧出, 等到你回過神時, 發覺自己已經被
一隻隻巨大的老鼠給....
LONG
    );
 set("exits",([ "east":__DIR__"birdpill4",
    ]));
 set("objects", ([__DIR__"npc/bigrat" : 6,
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

