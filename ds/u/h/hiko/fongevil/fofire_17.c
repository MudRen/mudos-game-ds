inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
這裡是火之試驗的盡頭，看來你已經沒什麼力氣在走下去
了，但是一想到肩上負的任務，你便只有股起餘勇勉力而行，
身上的衣服都已經汗濕了，這裡實在是極熱，讓你的體力不斷
的消耗完。
LONG
    );
 set("exits",([
"east":__DIR__"fofire_18",
"west":__DIR__"fofire_9",
"south":__DIR__"fofire_13",
"north":__DIR__"fofire_16",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             










