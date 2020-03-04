// This is a room made by roommaker.

inherit ROOM;

void create()
{
set("short", "海神塔");
set("long", @LONG
你走進塔的內部才知道這是一座專門祭祀海神的古塔。海神是海底居民所
信仰的神明，傳說中海神的個性雖然愛好和平，但是脾氣卻十分的火爆，一但
惹怒了祂，所有的生物都將面臨難以想像的浩劫。這裡有一張大桌子，上面放
了一些祭祀用的法器，西南方角落有個螺旋階梯可以通往上一層樓。   
LONG
);
set("objects",([
__DIR__"npc/towersoldier":2,
]));
set("exits", ([ 
  "east" : __DIR__"sea5",
  "up" : __DIR__"tower2",
]));
set("light",1);
set("no_clean_up", 0);
setup();
 load_object(__DIR__"sand1");
 load_object(__DIR__"sand2");
}
