inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
這裡是神之陣的三門，十分猛烈的氣息不斷的襲擊而來，
讓你有快要抵擋不住的錯覺，有著似是而非的奇特感覺，令你
無法分辨現實和幻覺的差異，如果不能保持清醒，可能會被虛
幻給擊敗了。
LONG
    );
 set("exits",([
"southwest" : __DIR__"fofantasy_20",
"north" : __DIR__"fofantasy_25",
"east" : __DIR__"fofantasy_18",]));
set("no_random_move","north");
setroom();
setup();
}             















