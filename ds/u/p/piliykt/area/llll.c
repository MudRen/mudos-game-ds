inherit ROOM;
void create()
{
set("short","樹洞");
set("long", @LONG
你好不容易鑽了近來, 卻發現這裡四處黑漆漆的, 根本看不到任何東
西, 你正思考你該不該繼續待在這地方北方隱約似乎有條小路.
LONG
);
set("exits", ([ 
                "north"  : __DIR__"tree3.c",
                "out"  : __DIR__"tree2.c",
                           ]));
         set("no_clean_up", 0);
setup();
        replace_program(ROOM);
}

