#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
set("short",HIC"�p�ж�"NOR);
 set("long", @LONG
�o�̦��@�ӰO�ƥ�(note)�C

LONG
);
set("light",1);

set("item_desc",([
"note":"�ڥ��ǲ�LPC���g�k...�Фj�a�h�h����...����.\n",
]));

set("exits",([
  "enter":"/u/g/genius/roomenter",
  "old":"/open/world1/meetroom",]));
 set("objects",([
 ]));
setup();
}
