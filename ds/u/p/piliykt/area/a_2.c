inherit ROOM;

void create()
{

set("short","小房間");
set("long", @LONG
這個房間到處堆滿了一大堆帳本, 在你的前方好像有個人正在清查帳
本, 你不經意的看了一下, 忽然想到........!!
LONG
);
set("world", "past");
set("light",1);
set("exits", ([                

"west" : __DIR__"aa_3.c", 
]));

setup();
}


