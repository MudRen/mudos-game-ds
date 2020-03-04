inherit ROOM;

void create()
{
set("short", "小樹林");
set("long", @LONG
走在林中，你只聞錚錚琴聲，一股淡淡白煙，帶著極甜的花香，自
密林深處傳出。一群乳白色的蜜蜂在你身旁飛來飛去。不論往哪兒走盡
是茂密的樹林。
LONG);
set("outdoors", "forest");
set("no_clean_up", 0);
setup();
replace_program(ROOM);
}
