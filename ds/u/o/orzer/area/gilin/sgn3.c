inherit ROOM;
void create()
{
        set("short","樹洞深處");
        set("long",@LONG
你來到了樹洞的最深處，這裡一片漆黑，讓人伸手不見五指，可是在洞
穴深處卻有著一道人型的微光，奇怪的吼聲就是由它所發出的，而靜心一聽
可以發現它似乎在講著話，雖然不是很清晰，不過也許它就是傳說的死靈？

LONG
        );
        set("exits", ([
  "east" : __DIR__"sgn2",
  ]));
        set("no_clean_up", 0);
        set("light",0);
        setup();
        replace_program(ROOM);
}










