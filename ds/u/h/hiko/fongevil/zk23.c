inherit ROOM;
void create()
{
        set("short","山間野林");
        set("long",@LONG
林間樹影隨風搖晃，印在地面有如鬼影幢幢，令人神經突然
繃緊，感覺好像會有不祥的事發生，林中地面濕濘不堪，走來甚
為不順，東南有一條山道，西南則是一道岩隙，南面有一條小路
。
LONG
);
  
set("exits", ([
  "south" : __DIR__"zk7",
  "southwest" : __DIR__"zk6",
  "southeast" : __DIR__"zk15",
]));
set("no_clean_up", 0);
set("outdoors","land");
setup();
}



