inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
終於到達火之測驗的終回了，只要打敗面前的人就能離開
了，因此你準備好要全力迎戰了，這裡看來更是炎熱，原來關
主的功夫的是構築在火上面，難怪整個測驗內都是火影不斷，
不過你的鬥志依然高昂。
LONG
    );
 set("exits",([
"north":__DIR__"fofire_23",
]));
 set("no_clean_up",0);
 set("light",1);
 set("boss",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}
