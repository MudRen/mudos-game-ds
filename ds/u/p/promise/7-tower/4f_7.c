#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short",HIC"《劍盟山底》"NOR);
  set ("long", @LONG
似乎這兒就是亞空間的內部，看到在旁的花草樹木都滿逼真似
的，不禁打從心理佩服此樓層塔主的功力深厚，能光憑內力便能把
此山脈擬的如此栩栩如生。
LONG
);
  set("exits", ([
  "northwest" : __DIR__"4f_8",
    ])); 
   
  set("no_clean_up", 0);
  set("light",1);
  setup();
 }



