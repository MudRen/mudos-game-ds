inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
你到處的尋找出路，可是總是找尋不到，現在你有些恍惚
了，你開始害怕無法離開這裡，可是卻也沒有方法，只有努力
堅持下去了，看了看四周圍一片火海，你只有嘆了口氣繼續前
進。
LONG
    );
 set("exits",([
"east":__DIR__"fofire_21",
"west":__DIR__"fofire_1",
"south":__DIR__"fofire_11",
"north":__DIR__"fofire_7",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             











