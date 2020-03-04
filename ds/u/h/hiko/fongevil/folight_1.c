inherit __DIR__"lightroom";
void create()
{
set("short","遺跡─光");
set("long",@LONG
你已經進入了遺跡光之試驗，這裡有著很多不可思議的光
線流竄，讓你有些睜不開雙眼，有時卻又十分柔和，讓人感到
非常無法了解這裡，這裡是光之試驗的三泉陣，四周有著一些
類似鏡子的東西。
LONG
    );
set("item_desc", ([
    "天照鏡" : (: look_mirror :),
    "mirror" : (: look_mirror :),
]));
set("exits",([
"southeast" : __DIR__"folight_3",
"southwest" : __DIR__"folight_2",
]));
set("light_room",__DIR__"folight_3");
set("light_number",1);
set("light_area","one");
setroom();
setup();
}   
