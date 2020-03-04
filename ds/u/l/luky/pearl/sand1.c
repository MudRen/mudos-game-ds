// Room: /u/l/luky/sea/sea1.c
#include <path.h>
inherit ROOM;
void create()
{
set("short", "小巷子");
set("long", @LONG
這個巷子十分狹窄. 地上還有許多的海砂。南方傳來一陣陣的海浪聲..
你突然想起從前這裡曾經是個大商港，可惜幾個月前強盜們在一次的總攻擊
時，將港口給徹底摧毀了，只剩下這片荒涼的景象。
LONG
);
set("exits", ([ 
  "south" : __DIR__"sand2",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
