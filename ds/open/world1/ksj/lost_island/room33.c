#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "遺世島－"HIW"石林上"NOR);
  set("long", @LONG
這裡是一小片化石樹林的頂端，石林密集而高聳，你幾乎無法看
到樹下的東西，東邊望過去可以看到一大片翠綠的草原，你可以試著
跳下去(jump down)。
LONG);
  set("exits", ([ /* sizeof() == 4 */
      "southwest" : __DIR__"room32",
      "northeast" : __DIR__"room34",
     ]));
  set("no_clean_up", 0);
  set("outdoors","forest");
  set("no_auc", 1);
  setup();
}

void init()
{
  add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg!="down" ) return 0;
  if(me->query_skill("dodge",2) <60)
  {
    message_vision("$N的輕身能力不足，不敢跳下去。\n",me);
    return 1;        
  }
  message_vision(HIW"$N提氣一躍而上，雙足連點，順利跳下石林。\n"NOR,me);
  me->move(__DIR__"room29");
  tell_room(environment(me),me->query("name")+"施展敏捷的身法，從石林上跳了下來。\n",me );
  return 1;
}
