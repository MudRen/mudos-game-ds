inherit __DIR__"waterroom";
void create()
{
 set("short","遺跡─水");
set("long",@LONG
你慢慢的一步步前進，聽著到處都有的轟轟水聲，讓你感
到十分不舒服，可是依然必須努力前進通過測驗，如果不使出
全力的話是不可能完成考驗的，看著眼前的路途你不禁堅定了
心神穩定的前進。
LONG
    );
 set("exits",([
"north":__DIR__"fowater_1",
"southeast" : __DIR__"fowater_5",
"southwest" : __DIR__"fowater_3",
]));
 setroom();
setup();
}             







