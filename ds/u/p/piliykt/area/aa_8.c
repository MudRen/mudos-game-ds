inherit ROOM;

void create()
{

set("short","臥房");
set("long", @LONG
你一走進這個房間, 就有一種臭味撲鼻而來, 讓你不竟想趕快逃離這
裡, 你看了一下四周, 發現到這裡的擺設相當簡單, 並無特別之處.
LONG
);
set("light",1);
set("exits", ([                
"east" : __DIR__"aa_4.c",        

]));

setup();
}



