#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","黑暗的倉庫");
set("long",@LONG
你一踏進這裡, 立刻被撲鼻的粉灰味嚇了一跳, 繼之才發現
這裡原來就是走私商交易的地方! 最危險的地方往往就是最安全
的地方, 誰會想到走私商的總部就在海政司呢? 而且這裡尚是工
地, 很少有人會來, 你看到中央有一個人正在叫賣, 看來便是頭
頭吧...?
LONG
    );
 set("exits",(["east":__DIR__"seacoun16",
]));
 set("objects", ([__DIR__"npc/jacklin" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             