inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
火焰的氣息越來越濃厚了，可能就快碰到什麼了，因此你
打醒了十二分精神準備應戰，但是不知道在何處，你心中的恐
懼正在加深，看了看四處的火苗也沒有答案，你心中只有快點
結束測驗的念頭。
LONG
    );
 set("exits",([
"east":__DIR__"fofire_15",
"west":__DIR__"fofire_25",
"south":__DIR__"fofire_17",
"north":__DIR__"fofire_19",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             










