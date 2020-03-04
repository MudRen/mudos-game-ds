/*
  [配置]水果販(Fruiterer)
  [配置]肉販(Meatman)
  [配置]魚販(Fishmonger)
  [配置]菜販(Greengroser)
*/
inherit ROOM;

void create()
{
        set("short", "果菜大市場");
        set("long", @LONG
這裡是港都 賽安尼爾斯中的果菜、魚肉買賣大市場，港都與鄰近城鎮的食物
    交易都在這個市場進行，你看到市場中攤位眾多，有各式各樣的蔬菜、水果、
    魚肉等，到處是攤販叫賣聲，非常地熱鬧吵雜。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room27",
  //"south" : __DIR__"room29",
  "northeast" : __DIR__"room53",
  //"east" : __DIR__"room28",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

