inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
這裡是神之陣的四門，十分猛烈的氣息不斷的襲擊而來，
讓你有快要抵擋不住的錯覺，有著似是而非的奇特感覺，令你
無法分辨現實和幻覺的差異，如果不能保持清醒，可能會被虛
幻給擊敗了。
LONG
    );
 set("exits",([
"northeast" : __DIR__"fofantasy_20",
"south" : __DIR__"fofantasy_25",
"west" : __DIR__"fofantasy_16",]));
set("no_random_move","south");
setroom();
setup();
}             















