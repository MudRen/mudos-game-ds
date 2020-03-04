#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIG"英文速查器"NOR, ({ "english translater", "translater", }));
  set("long", @LONG
請勿將此勿流傳出去。(用法 query <字>)
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

  if( !arg ) return notify_fail("用法: query <字>\n");
  "/adm/daemons/dictd.c"->find_word(me, arg);
  return 1;
}
