inherit ROOM;
void create()
{
        set("short","終極之路『第五層』");
      set("long",@LONG
這裡就是最後一層樓了，好像殺氣不斷從四面八方湧出，四周的牆壁
上有著一道道的裂痕，看起來這裡的樓主的確將念力修到一種最高層次，
看到四處無人的房間中，在一瞬間浮出一個人影將樓梯給撞斷了，四周的
氣氛是更加恐怖了。
LONG);
set("exits",([
       "back":__DIR__"9.c",
] ) );
set("objects",([
__DIR__"npc/lv6_king"          :1,
]));
set("outdoors","land");
        set("world", "future"); 
setup();
}
