inherit ROOM;

void create()
{
        set("short", "商店街－道具店");
        set("long", @LONG
這裡是港都商店街中的武器店，店門口的招排畫著太陽跟月亮，表示從白天
    到晚上都有營業，店中的架子、櫃子上依種類整齊地排放著各式道具。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room40",
  "southwest" : __DIR__"room44",
  //"north" : __DIR__"room34",
  "east" : __DIR__"room45",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

