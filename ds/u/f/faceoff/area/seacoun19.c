inherit ROOM;

void create()
{
set("short", "老記當鋪");
set("long", @LONG
這是一間很久很久以前就存在的當鋪, 當年無砂鎮正逢轉
型之時, 就是這間當鋪以高價收購鄉親的財物, 幫助了許多後
來的富商, 如果說有今日的無砂是因為有昔日的老記也不為過
.
LONG
        );
set("exits", ([ "west" : __DIR__"seacoun6",
]));
set("objects", ([__DIR__ "npc/salesman2" : 1,
    ]));

set("room_type","shop");
set("no_clean_up", 0);
set("light",1);
setup();
}