#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", CYN"向古"HIC"劍亭"NOR);
  set ("long", @LONG
很平凡的一個涼亭，但走到了這裡感覺就跟之前所走過的地方不
同，前方有位老者在那裡休憩，或許可以向那位老者打聽一下，怎樣
脫離這兒。
LONG
);
  set("exits", ([
  "east" : __DIR__"4f_3",
    ])); 
   set("objects", ([ /* sizeof() == 1 */
   __DIR__"oldman":1, 
]));

  set("no_clean_up", 0);
  set("light",1);
  setup();
 }


