inherit ROOM;

void create()
{
set("short", "愛門村");
        set("long", @LONG
你的正前方是一排一排桃樹，現在的氣候恰到好處，樹上綻放著紅色的
花朵，相當的炫目。桃酒是這裡的居民一大飲品，桃酒同時也用來與葡萄酒
或是小麥酒調成風味獨特的飲料。遠處不時可以聽見村民們的談話聲，為鄉
間小道添加一些聲響。
LONG
        );
        set("exits", ([
     "northeast":__DIR__"al1",
     "west":__DIR__"al13",
     "south":__DIR__"al3",
]));

        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
