inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
這裡是人之陣的者眼，有著眾多的奇特影子環繞此地，好
像一不小心就會有危險，到處都充滿著幻惑人心的幻影，令你
一時神智有些恍惚的感覺，如果不能保持清醒，可能就無法突
破測驗了。
LONG
    );
 set("exits",([
"southwest" : __DIR__"fofantasy_4",
"northeast" : __DIR__"fofantasy_10", 
"northwest" : __DIR__"fofantasy_6",
"southeast" : __DIR__"fofantasy_2",]));
set("no_random_move","southeast");
setroom();
setup();
}             














