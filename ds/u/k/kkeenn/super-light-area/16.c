inherit ROOM;
void create()
{
      set("short","終極之路『第三層』");
      set("long",@LONG
這裡的路好像更發難走了，整個空間好像跟時光混在一起，像是那虛
無渺茫的幻境，突然一聲機械式的爆炸破壞了這一切的寧靜，一隻武裝的
機器碼衝到你眼前，在你眼前幻化成一隻機器人，擋住了往上的樓梯。
LONG);
set("exits",([
      "up":__DIR__"17.c",
      "down":__DIR__"15.c",
] ) );
set("objects",([
__DIR__"npc/lv4_king"        :1,
]));
set("outdoors","land");
        set("world", "future"); 
setup();
}
