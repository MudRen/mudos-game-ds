#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
set("short",HIC"小房間"NOR);
 set("long", @LONG
這裡有一個記事本(note)。

LONG
);
set("light",1);

set("item_desc",([
"note":"我正學習LPC的寫法...請大家多多指教...謝謝.\n",
]));

set("exits",([
  "enter":"/u/g/genius/roomenter",
  "old":"/open/world1/meetroom",]));
 set("objects",([
 ]));
setup();
}
