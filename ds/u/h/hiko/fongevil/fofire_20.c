inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
你看著四周燒著的火焰，差點以為自己在地獄中，這地方
讓人沒有多呆一分鐘的想法，你心中只有快離開，現在你十分
的疲累，撐住你的想法只有趕快打到妖孽，你只有慢慢的繼續
前進。
LONG
    );
 set("exits",([
"east":__DIR__"fofire_14",
"west":__DIR__"fofire_6",
"south":__DIR__"fofire_5",
"north":__DIR__"fofire_18",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             










