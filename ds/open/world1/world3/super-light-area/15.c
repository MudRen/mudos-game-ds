inherit ROOM;
void create()
{
      set("short","終極之路『第二層』");
      set("long",@LONG
這裡四周充斥著一股詭譎的氣息，彷彿天地萬物都在這裡變的灰暗，
死亡的魄力散佈在整個房間裡，在這種鳥不生蛋的地方，竟然有人在一旁
靜靜的觀賞你被這裡的氣氛搞的暈頭轉向，似乎很欣賞這種痛苦的表情！
LONG);
set("exits",([
      "up":__DIR__"16.c",
      "down":__DIR__"14.c",
] ) );
set("objects",([
__DIR__"npc/lv3_king"      :1
]));
set("outdoors","land");
        set("world", "future"); 
setup();
}
