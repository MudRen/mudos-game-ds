#include <ansi.h>
inherit MOBROOM;

void create()
{
  set("short", "���s��"HIR"�Ĥ@�h"NOR);
  set("long", @LONG
�i�J���a��A�oı�������A���ƹD�s���¦�ŧ���ӡA���H�P���
���M�A�������ˡA�Q�������}���a�A��~�I�l�s�A�Ů�C
LONG);
  set("exits", ([
  "northwest" : __DIR__"room7",
  "southwest" : __DIR__"room5", ]));
  set("mob_amount",4);
  set("chance",99);  
  set("no_member",1);  set("no_member",1);  set("mob_object",({
  __DIR__"npc/big-claw dragon",
}));
  set("no_clean_up",0);
  set("outdoor",0);
  setup();
}

