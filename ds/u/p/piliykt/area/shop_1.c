inherit ROOM;

void create()
{

set("short","小藥鋪");
set("long", @LONG
這裡是神木村裡的重要地方, 有很多生病的人都來這個地方求醫, 希
望能康復.你看了看四周, 發現牆上掛了一付匾額, 四周很多的人等待看
病, 不竟讓你好奇,想見一見這間藥鋪的主人.
LONG
);

set("light",1);
set("exits", ([                
        "south" : __DIR__"road_5.c", 
   ]));

 setup();
}


