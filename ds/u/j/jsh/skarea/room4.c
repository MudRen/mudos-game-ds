inherit ROOM;

void create()
{
        set("short", "市場");
        set("long", @LONG
這裡是港都 賽安尼爾斯中的果菜、魚肉買賣大市場，港都與鄰近城鎮的食物
交易都在這個市場進行，你看到市場中攤位眾多，有各式各樣的蔬菜、水果、魚肉
等，到處是攤販叫賣聲，非常地熱鬧吵雜。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room7", 
  "west" : __DIR__"room1", 
  "south": __DIR__"room5",
  //"north": __DIR__"room4", 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


