inherit ROOM;

void create()
{

set("short","二樓走道");
set("long", @LONG
這裡有許多的房間, 提供給來這嫖妓的客人使用, 你站在這走道隱約
還可以聽到些微弱的喘息聲, 始你不竟臉紅心跳加數.
LONG
);
set("light",1);
set("exits", ([                
         
         "down" : __DIR__"sex_2.c",   
         "west" : __DIR__"sex_7.c",   
         "east" : __DIR__"sex_8.c",   
               ]));

 setup();
}

