/*
  [配置]水果販(Fruiterer)
  [配置]肉販(Meatman)
  [配置]魚販(Fishmonger)
  [配置]菜販(Greengroser)
*/
//海軍長官 1 位
inherit ROOM;

void create()
{
        set("short", "海軍分部－大門");
        set("long", @LONG
這裡是海軍分部的大門口，門旁邊的黃銅牌子上刻著海鷗標記以及
    "ＭＡＲＩＮＥ"，兩旁有海軍的哨兵正在站哨，往裡面看過去可以
    看到白色的建築物及寬闊的操場。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room32",
  "south" : __DIR__"room36",
  "north" : __DIR__"room30",
  "east" : __DIR__"room34",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

