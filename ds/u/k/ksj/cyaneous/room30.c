/*
  [配置]水果販(Fruiterer)
  [配置]肉販(Meatman)
  [配置]魚販(Fishmonger)
  [配置]菜販(Greengroser)
*/
//海軍 4 位
inherit ROOM;

void create()
{
        set("short", "海軍分部－集合場");
        set("long", @LONG
這裡是海軍的集合場，海軍的整隊、操練和檢閱都在這邊進行，場上有些海
    軍正在進行訓練。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"room12",
  "south" : __DIR__"room33",
  //"north" : __DIR__"room26",
  //"east" : __DIR__"room28",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

