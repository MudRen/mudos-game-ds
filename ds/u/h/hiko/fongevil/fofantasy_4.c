inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
這裡是人之陣的二門，有著眾多的奇特影子環繞此地，好
像一不小心就會有危險，到處都充滿著幻惑人心的幻影，令你
一時神智有些恍惚的感覺，如果不能保持清醒，可能就無法突
破測驗了。
LONG
    );
 set("exits",([
"southwest" : __DIR__"fofantasy_1",
"northeast" : __DIR__"fofantasy_7",
]));
setroom();
setup();
}             












