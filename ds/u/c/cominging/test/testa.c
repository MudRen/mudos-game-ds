#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIG"�^��t�d��"NOR, ({ "english translater", "translater", }));
  set("long", @LONG
�ФűN���Ŭy�ǥX�h�C(�Ϊk query <�r>)
LONG);
  setup();
}

void init()
{
  add_action("do_query", "query");
}

int do_query(string arg)
{
  object me;
  me = this_player();

  if( !arg ) return notify_fail("�Ϊk: query <�r>\n");
  "/adm/daemons/dictd.c"->find_word(me, arg);
  return 1;
}
