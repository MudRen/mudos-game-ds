inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
你已經進入了遺跡幻之試驗，你發現到空氣中的恐怖氣息
越來越強大，這裡想必有著不尋常的東西，不小心一點的話可
能很難突破這裡，這裡看來應該是四幻陣的神之陣，看來不是
可以放心的地方。
LONG
    );
 set("exits",([
"southwest" : __DIR__"fofantasy_24",
"northeast" : __DIR__"fofantasy_21",
"northwest" : __DIR__"fofantasy_23",
"southeast" : __DIR__"fofantasy_22",
]));
setroom();
setup();
}             















