#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞窟");
        set("long",@LONG
這裡是一個不會黑的山洞，你深入洞裡，只見周遭越來越暗，不時還有
猛獸的聲音，你心裡害怕極了，只想敢快離開這個山洞，要離開得時候你發現
到角落有一座雕像，你心有領悟的說:原來是這個在發光ㄚ，在你說的同時，有
一隻蝙蝠從你的頭上掠過,你嚇了一跳..。
LONG       );
        set("exits", ([ /* sizeof() == 1 */
  "down" :"/u/t/tako/area/room~2.c",
]));
        set("objects", ([ /* sizeof() == 1 */
       "/u/t/tako/statue.c" : 1,
        ]));
        set("outdoors","land");
    set("light",1);
        set("no_clean_up", 0);
       setup();
}

