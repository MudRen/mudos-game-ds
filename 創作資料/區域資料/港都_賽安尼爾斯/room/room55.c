inherit ROOM;

void create()
{
  set("short", "道路");
  set("long", @LONG 
這裡是港都對大陸的經商要道，一些商品貨物都要經過這條道路
到運送到港都進行買賣，不分晝夜經常看得到貨車、小販行走在路上
。 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room56",
      "west" : __DIR__"room54",
     ])); 
  set("light",1);
  setup();
}
