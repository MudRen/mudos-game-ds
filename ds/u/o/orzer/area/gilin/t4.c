inherit ROOM;
void create()
{
        set("short","祭靈森林西側");
        set("long",@LONG
你走到了森林的幽暗處，這裡看來就連光都很難照進來，令人不由
自主的緊張了起來，再加上籠罩著整座森林的詭異氣息，真是很使人害
怕，不知道應不應該前進，附近連一點聲息都沒有。
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t3",
  "west" : __DIR__"t5",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








