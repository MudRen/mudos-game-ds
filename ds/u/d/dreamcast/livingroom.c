#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", HIC"DREAMCAST'S"HIG"-"HIM"LIVINGROOM"NOR) ;
   set ("long", 
"�o�̬Odream�M�Ϊ����U�A�̭����]�Ƭ۷�����A
�~���ǨӰ}�}������n�Ať�Fı�o�߱��}��...\n") ;
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"workroom", 
]));
        set("objects",([
                   __DIR__"tv" : 1,
                 ]) );
  setup();
               


}

