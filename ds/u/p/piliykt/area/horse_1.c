inherit ROOM;

void create()
{

set("short","小房屋");
set("long", @LONG
你一進入這個屋子便聽到優美的琴聲 ,你觀察了四周發現牆上掛滿了
樂譜, 在你的前方有個人正在彈著他的琴, 你仔細的看了他一眼,不竟被他
嚇了一跳, 他全身散發一股殺氣.
LONG
);
set("light",1);
set("exits", ([                
        "out" : __DIR__"road_2.c", 
     
   ]));

 setup();
}

