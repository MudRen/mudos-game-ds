inherit __DIR__"waterroom";
void create()
{
set("short","遺跡─水");
set("long",@LONG
你從南邊的水幕隱隱感到一股殺氣，最後的測驗者就在那
裡了，如果準備好了迎戰的把握就前進吧，只要突破了眼前的
唯一關卡便就結束測驗了，當然如果你走不過去就回去繞繞吧
。
LONG);
set("exits",([
"south":__DIR__"fowater_26", 
"northeast":__DIR__"fowater_23",
"northwest":__DIR__"fowater_22",
]));
set("high_water","south");
setroom();
setup();
}             










