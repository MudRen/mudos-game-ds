#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"木樁陣中"NOR);

 set("long",@LONG
 
  你覺得四周被木樁擠的換不過氣來, 既之發現這是你的心理作用,
可見對你已經感到一定程度的心慌意亂了....你心中不禁希望感快走
出這一個令人心慌了地方...這裡的[1;33m地上有一個腳印[0m...

[1;37m
[提示: 如果你身上有東西的話, 可以利用drop 東西來辨認位置.]
[      你也可以用look <east.north.west.south>方向,再前進 ]
[      這裡地上的腳印就是線索。                          ]

[1;32m 如果真的走不出去, 就打 recall start 吧。
[0m
��╲                                                 ╱��
��▕＿                                             ＿▏��
��▕ :▏                                         ▕: ▏��
��▕ :▏                                         ▕: ▏��
��▕￣                                             ￣▏��
��╱                                                 ╲��
LONG
    );
 set("exits",([ "west":__DIR__"wood2.c",
                "east":__DIR__"wood2.c",
                "north":__DIR__"wood2.c",
                "south":__DIR__"wood2.c",
    ]));

 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
