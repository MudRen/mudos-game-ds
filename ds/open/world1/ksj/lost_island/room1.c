#include <ansi.h>
inherit ROOM;

void create()
{
  set("short","岩壁下");
  set("long", @LONG
這裡是一處高聳岩壁的底下，四周是狹窄的砂礫灘，浪潮不時拍
打岸邊，濺起的海水弄得你全身濕濕黏黏地，海灘的周圍除了海水就
是岩壁，看來沒有其它出路了，除非跳上岩壁(jump)。
LONG
);
  set("no_clean_up", 0);
  set("outdoors","land");
  set("no_auc", 1);
  set("item_desc", ([
      "岩壁" : "高約數丈的一片岩壁，陡峭而濕滑。\n",
     ]));
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
  if(!arg || arg!="岩壁" ) return 0;
  if(me->query_skill("dodge",2) <40)
  {
    message_vision( "$N使盡了招式，但縱躍能力不足，怎麼都跳不上岩壁。\n" ,me);
    return 1;        
  }
  message_vision(HIW"$N提氣一躍而上，雙足輕踩岩壁，幾次借力後身影消失在岩壁的另一方。\n"NOR,me);
  me->move(__DIR__"room2");
  tell_room(environment(me),me->query("name")+"施展純熟的身法，從岩壁上跳了下來。\n",me );
  return 1;
}
