inherit __DIR__"waterroom";
void create()
{
set("short","遺跡─水");
set("long",@LONG
你現在已經慢慢接近終點了，離最後的測驗越來越靠近了
，想到此你也不禁有點害怕，但是卻也不想中途放棄繼續前進
因此你只好鼓起餘勇進續前進，心中有著一些些的害怕，可是
依然穩定的邁向測驗。
LONG);
set("exits",([
"northeast":__DIR__"fowater_14",
"south":__DIR__"fowater_16",
]));
setroom();
setup();
}             










