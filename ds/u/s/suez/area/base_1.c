#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "地下密室");
	set("long",@LONG 
這裡是一間地下密室，四周的木板還保有木屑的香氣，顯然這裡才剛剛
建好不久。往西邊看去，隱隱約約可以看到一些人影，似乎還能聽見交談聲
和兵器交擊聲。你不禁懷疑，到底是什麼人會在這種地道內呢？
LONG
);
	set("exits", ([ /* sizeof() == 1 */
                   "west" : __DIR__"base_5",
               ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}