inherit ROOM;

void create()
{

set("short","大街");
set("long", @LONG
你正站在大街上, 這裡人聲鼎沸, 車水馬龍, 熱鬧非凡.來往
的過路人很多, 兩旁有許多的房屋, 建築的非常漂亮.在你的右邊
有一棟漂亮的大戶人家,往東到達中央廣場.
LONG
);
set("outdoors", "desert");

set("exits", ([                
         "west" : __DIR__"road_3.c", 
         "enter": __DIR__"horse_2.c",       
         "east" : __DIR__"road_5.c",
   ]));

 setup();
}


