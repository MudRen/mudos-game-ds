inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
這裡看來已經是測驗的最後一關了，十分猛烈的氣息不斷
的襲擊而來，而你的眼前有著一隻十分奇特的幻獸，不打敗它
可能就無法前進了，後方隱隱傳來一股壓迫感，讓你不禁捏了
一把冷汗。
LONG
    );
 set("exits",([
"north" : __DIR__"fofantasy_15",
"south" : __DIR__"fofantasy_boss",
]));
setroom();
setup();
}             














