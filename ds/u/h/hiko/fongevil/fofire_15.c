inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
你在火之遺跡不斷尋找出路，但是實在是找不到一條通路
，你已經因為大火而快煮熟了，心中不斷冒出放棄放棄的念頭
，身上的衣服快焦掉了，你很怕等等要空身測驗，一想到如此
你就更加努力找尋出路。
LONG
    );
 set("exits",([
"east":__DIR__"fofire_2",
"west":__DIR__"fofire_16",
"south":__DIR__"fofire_8",
"north":__DIR__"fofire_20",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             










