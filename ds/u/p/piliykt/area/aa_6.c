inherit ROOM;

void create()
{

set("short","趙書宇臥房");
set("long", @LONG
這裡就是趙書宇的臥房了, 這裡的擺設完全是有錢人家的大千金, 你
發現到周圍的桌上都擺滿了胭脂與花粉, 你再看了一下, 才發現到不只是
胭脂花粉, 連衣櫥都塞滿了衣裙. 
LONG
);
set("light",1);
set("exits", ([                
"north" : __DIR__"aa_4.c",        
]));
set("objects",([
__DIR__"npc/girl_1.c" : 1,
       ]) );

setup();
}

