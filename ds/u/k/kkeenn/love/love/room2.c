inherit ROOM;
void create()
{
        set("short", "情城池廣場");
        set("long", @LONG
寬闊廣場裡的地上是由各種美麗的壓克力磚所成的，每天早晨先迎接
客人的就是這些美麗的壓克力磚。你正在情城池正中心廣場的中央，往前
直走就是傳說中的情城池了，往其他就是情城的住戶。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"room1",
  "northeast" : __DIR__"room3",
  "northwest" : __DIR__"room4",
  "north" : __DIR__"room5",
  "southeast" : __DIR__"room6",
  "southwest" : __DIR__"room7",  
]));
set("no_recall",1);
set("light",1);
        set("objects", ([
 __DIR__"npc/dwller" : 3,
__DIR__"npc/obj/well"  :1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}

