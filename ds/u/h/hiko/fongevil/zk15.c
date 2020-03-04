inherit ROOM;
void create()
{
        set("short","山道");
        set("long",@LONG
你走在山道上，發覺此地好像有人修整過，山道上還有石階，看來此
地以前該有進行什麼事，要利用到山道來運送東西，可能是古代遺跡，自
東南和西北望去有著一堆野林。
LONG
        );
  
set("exits", ([
  "southeast" : __DIR__"zk16",
  "northwest" : __DIR__"zk23", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}



