inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
這裡是地之陣的三門，有著很多無法了解的光靈存在，好
像一不小心就會有危險，到處都充滿無法預知的錯覺，令你沒
法放心的行走，如果保持著警覺心的話，可能會遭受到猛烈的
傷害。
LONG
    );
 set("exits",([
"west" : __DIR__"fofantasy_5",
"north" : __DIR__"fofantasy_10", 
"east" : __DIR__"fofantasy_15",
"south" : __DIR__"fofantasy_8",
]));
set("no_random_move","east");
setroom();
setup();
}             















