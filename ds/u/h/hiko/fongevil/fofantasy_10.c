inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
你已經進入了遺跡幻之試驗，這裡到處充滿著許多的光影
看來模糊不清，而且充滿著幻覺，如果不小心被迷惑的話，可
能很難突破這裡，這裡看來應該是四幻陣的地之陣，感覺有些
奇特的東西充滿此地。
LONG
    );
 set("exits",([
"west" : __DIR__"fofantasy_12",
"east" : __DIR__"fofantasy_14",
"north" : __DIR__"fofantasy_11",
"south" : __DIR__"fofantasy_13",
]));
setroom();
setup();
}             













