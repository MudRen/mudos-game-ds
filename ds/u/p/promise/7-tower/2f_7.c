#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIG"風華草居"NOR);
  set ("long", @LONG
在這個塔裡面，居然有這麼一個清閒的地方，感覺像似個陷阱般
的恐怖，在裡頭住了一個老道士，若無其事的在那邊發著呆，總之，
整體似乎有種說不出來的怪疑惑著你。
LONG
);
        set("exits", ([
  "southwest" : __DIR__"2f_6",
     ]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"taoist" : 1,
        ]));

  set("no_clean_up", 0);
  
  setup();
 }

