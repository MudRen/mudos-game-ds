//u/c/chiaa/world2/blackly_forest/garrison1.c

#include <ansi.h>   //定義顏色
inherit ROOM;

void create ()
{
  set("short", "駐守處");
  set("long", @LONG
這裡是忍者村的駐守處,有幾個穿著類似忍者服裝的人,
正盯著你看,對於外面的訪客,他們保持高度的警戒心,
使你自己感覺到還是不要輕舉妄動的好!!
LONG
        );


  set("exits", ([ /* sizeof() == 1 */
   
  "east"  : __DIR__"garrison2",         //駐守處2
   
]));


 setup();
  replace_program(ROOM);
}
