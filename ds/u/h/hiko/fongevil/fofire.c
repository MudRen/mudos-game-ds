inherit ROOM;
void create()
{
 set("short","遺跡─火");
set("long",@LONG
你剛踏進來便覺得佈置十分的炎熱，令你感到渾身不舒服
，這裡就是遺跡中的火之試驗的起始點，可想而知一路上將有
許多凶險，因此這裡可能是最安全的地方，若準備好的話就請
出發面對考驗吧！
LONG
    );
 set("exits",([
"down":__DIR__"fofire_1",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             


