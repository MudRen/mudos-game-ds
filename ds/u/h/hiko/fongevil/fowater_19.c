inherit __DIR__"waterroom";
void create()
{
set("short","遺跡─水");
set("long",@LONG
這個房間的南邊出口充滿著水，看來就照著經驗把機關解
除便能通行了，如果之前沒有解除的話請再回去繞繞吧，只要
通過此地離終點就十分接近了，看著一片水波席捲的區域，你
也開始覺得緊張了。
LONG);
set("exits",([
"south":__DIR__"fowater_20", 
"east":__DIR__"fowater_18",
"west":__DIR__"fowater_16",
]));
set("high_water","south");
setroom();
setup();
}             










