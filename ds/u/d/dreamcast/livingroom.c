#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", HIC"DREAMCAST'S"HIG"-"HIM"LIVINGROOM"NOR) ;
   set ("long", 
"這裡是dream專用的客廳，裡面的設備相當齊全，
外面傳來陣陣放浪濤聲，聽了覺得心情開朗...\n") ;
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"workroom", 
]));
        set("objects",([
                   __DIR__"tv" : 1,
                 ]) );
  setup();
               


}

