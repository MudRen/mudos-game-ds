#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","青石路");
 set("long",@LONG
青石路給人的感覺相當的出世，而你現在所走的青石路
是往下山的方向，也就是從奇倪峰行向妄莒峰，不過在妄莒
峰之上有一個大神廟，因此在口語上妄莒也不是一座峰了， 
從這裡往東可以到那間神廟，而往西則會回到奇倪峰....
LONG
    );
 set("exits",([  "eastup":__DIR__"ten43",
              "westup":__DIR__"ten5",
    ]));
 set("objects", ([__DIR__"npc/dog" : 2,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}


