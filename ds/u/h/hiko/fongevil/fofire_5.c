inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
你已經進入了遺跡火之試驗，這裡到處冒出火焰令你感到
十分不舒服，如果力量不夠可能就撐不下去了，看來要征服這
裡要花上很多努力，請全力衝刺吧，一旦停頓下來將是不可能
通過考驗的。
LONG
    );
 set("exits",([
"east":__DIR__"fofire_12",
"west":__DIR__"fofire_1",
"south":__DIR__"fofire_16",
"north":__DIR__"fofire_6",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             





