// 犯人3位

inherit ROOM;

void create()
{
        set("short", "海軍分部－監牢");
        set("long", @LONG
這裡是海軍分部的附設監牢，四周牆壁以鐵板覆蓋只留下一道小小的通風鐵
    閘，牢門以粗實的鐵柱圍成，即使用鋒銳的刀劍也砍不斷。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"room14",
  //"south" : __DIR__"room39",
  "north" : __DIR__"room34",
  //"east" : __DIR__"room34",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

