inherit __DIR__"waterroom";
void create()
{
 set("short","遺跡─水");
set("long",@LONG
你已經進入了遺跡水之試驗，這裡到處充滿水柱令你感到
十分不舒服，如果閃躲不掉可能會受到很大的傷害了，看來要
通過這裡並不是容易的事，如果不全力以赴的話下場可能不怎
麼好看。
LONG
    );
 set("exits",([
"south":__DIR__"fowater_2",
]));
setroom();
setup();
}             








