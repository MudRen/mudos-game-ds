inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
你有一種感覺似乎快到了，在這種地方不斷行走你已經有
野獸的直覺了，但是不知道是哪種野獸罷了，想到如此你就越
想快脫離火之試驗，這裡完全不是人能忍受的地方，你心中只
有快點結束測驗的念頭。
LONG
    );
 set("exits",([
"east":__DIR__"fofire_4",
"west":__DIR__"fofire_18",
"south":__DIR__"fofire_22",
"north":__DIR__"fofire_12",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             










