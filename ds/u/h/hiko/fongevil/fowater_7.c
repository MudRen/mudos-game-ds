inherit __DIR__"waterroom";
void create()
{
set("short","遺跡─水");
set("long",@LONG
你來到了一個奇特的房間，房間的另一個出口充滿著水，
讓你覺得很奇怪，看來要用些機關才能把水消掉，但是眼前卻
找不到有任何機關，看來是在之前就出現過了，如果還是走不
過去就回去繞繞吧。
LONG);
set("exits",([
"south":__DIR__"fowater_8", 
"northeast":__DIR__"fowater_5",
"northwest":__DIR__"fowater_3",
]));
set("high_water","south");
setroom();
setup();
}             








