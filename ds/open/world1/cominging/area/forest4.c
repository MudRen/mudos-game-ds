inherit ROOM;
void create()
{
        set("short", "森林間空地");
        set("long",@LONG
這裡是森林間的空地，在這的北方是通往步靈城的路，你看到路上
旁的樹上偶爾冒出幾條血紅色的舌頭，似乎就是這一帶森林中的獵人，
紅毒蛇，其身體全紅近朱，看過其全身的人不多，往東邊是一個小村，
而往西南邊依舊是森林, 旁邊有個小招牌(sign)。
LONG
        );
        set("exits", ([
  "southwest" : __DIR__"forest5.c",
  "north" : __DIR__"forest3.c",
//  "east" : __DIR__"villagein.c",
]));
        set("item_desc", ([
  "sign" : "一個招牌, 上面寫著, '修得村目前暫不開放, 因上次地震震壞了∼！' \n"
]));
        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

