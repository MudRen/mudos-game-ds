inherit ROOM;
void create()
{
     set("short","終極之路『第一層』");
      set("long",@LONG
這裡是粉恐怖的終極之塔的第一層，很明顯的這裡的機器人均是千年
前的百年高人鎮守著，看來都不太好惹，你將會陷入進退兩難的境地，
是讓稍有根基的人練功用的....
LONG);
set("exits",([
       "down":__DIR__"13.c",
       "up":__DIR__"15.c",
]) );
set("objects",([
__DIR__"npc/lv2_king"    :1
]));
        set("world", "future"); 
setup();
}
