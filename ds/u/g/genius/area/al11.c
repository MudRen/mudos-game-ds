inherit ROOM;

void create()
{
set("short", "愛門村小路");
        set("long", @LONG
這裡是愛門村北邊的小路，沿著這條路過去就可以走上西邊的丘陵。這
附近有一棵比較挺直的大樹，偶而可以看到松鼠在枝椏間活動。
LONG
        );
        set("exits", ([
     "east":__DIR__"al12",
     "south":__DIR__"al10",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
