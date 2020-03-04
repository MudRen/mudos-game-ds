// road1.c 小路

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
說是路，其實是人才草原上走過留下的痕跡，天長日久就漸漸行成了。
這只哈薩克部族在這裡定居已久，可以看見到處是這種原始的道路。
LONG
        );

        
        set("exits", ([
           "northeast" : __DIR__"gebi5",
            "west" : __DIR__"road2",
        ]));

        set("outdoors", "land");
        
        setup();
        replace_program(ROOM);
}
