inherit ROOM;

void create()
{

set("short","趙王臥房");
set("long", @LONG
這裡就是趙王劉煜的臥房了, 你看了四周, 發現這裡的任何一樣物品
都是很珍貴的, 在你的左方掛了幾幅畫. 
LONG
);
set("light",1);
set("exits", ([                
"south" : __DIR__"aa_4.c",        

]));
set("objects",([
__DIR__"npc/king1.c" : 1,
              ]) );

setup();
}


