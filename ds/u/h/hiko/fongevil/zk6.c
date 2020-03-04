inherit ROOM;
void create()
{
        set("short","岩隙");
        set("long",@LONG
此地是由山中強風吹蝕造成的岩隙，岩壁看來有如刀削一般，而且路
面極為平坦，走起來有如踏在平地，可是路極狹小只得一人肩寬，走起來
甚為驚險，東北是一堆野林，西南可以看見一座小丘。
LONG
        );
  
set("exits", ([
  "southwest" : __DIR__"zk5",
  "northeast" : __DIR__"zk23", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




