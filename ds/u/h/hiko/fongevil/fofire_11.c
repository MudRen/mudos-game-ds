inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
你已經進入了遺跡火之試驗，這裡到處冒出火焰令你感到
十分不舒服，想要通過測驗的路還很漫長，但是只有死命撐下
去才能成功，因此雖然全身發熱你還是咬緊牙根走下去，一旦
稍停火焰就追上來了。
LONG
    );
 set("exits",([
"east":__DIR__"fofire_7",
"west":__DIR__"fofire_10",
"south":__DIR__"fofire_3",
"north":__DIR__"fofire_12",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             









