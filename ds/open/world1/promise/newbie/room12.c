#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "���s��"HIR"�ĤG�h"NOR);
  set("long", @LONG
�i�J���a��A�oı�������A���ƹD�s���¦�ŧ���ӡA���H�P���
���M�A�������ˡA�Q�������}���a�A��~�I�l�s�A�Ů�C
LONG);
  set("exits", ([
  "north" : __DIR__"room11",
  "south" : __DIR__"room13",
 ]));
  set("no_member",1); 
  set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/dragon-queen" : 1,
]));

    set("no_clean_up",0);
  set("outdoor",0);
  setup();
}

