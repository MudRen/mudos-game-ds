inherit ROOM;

void create()
{

set("short","百花樓");
set("long", @LONG
這是一家妓院, 裡面不知道多少的漂亮姑娘正等者你, 你光看門口滿
天發光金光閃閃, 不竟想進去快樂一下, 解放自己休息一下.  
LONG
);
set("light",1);
set("exits", ([                
         "enter" : __DIR__"sex_2.c",   
         "west" : __DIR__"road_7.c",   
   ]));

 setup();
}

