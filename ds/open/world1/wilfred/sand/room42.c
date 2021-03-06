#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIW"磐龍險灘"NOR);
  set ("long", @LONG
滔滔江水，翻濁騰湧激起朵朵白色浪花，這裡便是故年遺跡，寒
風肅肅，有肅殺之聲，極目望去，遠方似有一座山，但苦於大江阻隔
，無法靠近看清。
LONG
);

  set("exits", ([
  "east" : __DIR__"room41",
  "south" : __DIR__"room94",
]));

  set("item_desc", ([
  "山" : "你極力想看清遠方的山，但苦於距離過遠，無法看得真切。朦朧中，隱約看到有建築物，看來只有想辦法過河才能一探究竟。\n",
]));
          set("objects", ([ /* sizeof() == 1 */
            ]));

  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
}

void init()
{
  write(HIW"南邊便是滔滔江水了，只見江水翻濁騰湧激起朵朵白色浪花，聲勢浩大。\n"NOR);
}

int valid_leave(object me, string dir)
{
  object horse, boots;
  horse = present("fierce-wind horse",me);
  boots = present("water boots",me);

  if(environment(me) && dir == "south")
  {
    if(horse)
    if(objectp(horse = me->query_temp("ride")) )
    {
      message_vision("$N跨下的$n一聲長嘶，隨即奮力的朝對岸跳了過去。\n",me,horse);
      me->move(__DIR__"room46");
      return notify_fail("");
    }
    if(boots)
    if( stringp(boots->query("equipped")) )
    {
      message_vision("$N腳穿踏水鞋，平穩的在江面上踏水而去。\n",me);
      me->move(__DIR__"room46");
      return notify_fail("");
    }
    message_vision("$N亳不猶豫的便縱身跳入了水中.....\n",me);
    remove_call_out("check_sk");
    call_out("check_sk",2,me);
    return notify_fail("");
  }
  return ::valid_leave(me,dir);
}

int check_sk(object me)
{
  int index = me->query_skill("swim");
  me->move(__DIR__"room94");
  if( index > 20 )
  {
    message_vision(HIC"$N使出了超絕的泳技，身如蛟龍般往對岸遊了過去。\n"NOR,me);
    me->move(__DIR__"room46");
  }
  else
  {
    if( random(index) > 14 )
    {
      message_vision("只見$N慌張慌張的遊向對岸，雙手亂划，還吃了幾口水。\n",me);
      me->move(__DIR__"room46");
      message_vision("$N狼狽的爬上岸來，回頭望著滔滔江水，心有餘悸。\n",me);
    }
    else
    {
      message("world:world1:vision","\t"+ me->name(1)+ "淒慘的大叫： 救命哪！救命哪！...咕嚕咕嚕...\n",users());
      me->start_busy(2);
      call_out("trouble",1,10);
    }
  }
  return 1;
}

int trouble(int index)
{
  object me = this_player();
  me->start_busy(2);
  if(!index)
  {
    me->move(__DIR__"room42");
    message_vision(HIW"$N終於又被沖回了岸上....\n"NOR,me);
    return 1;
  }
  switch(random(3))
  {
    case 0 : message_vision("$N在慌亂中又吃了幾口水....\n",me);
             break;
    case 1 : message_vision("$N在水中載浮載沉的，相當狼狽....\n",me);
             break;
    case 2 : message_vision("$N的雙手亂抓，卻抓不到什麼....\n",me);
             break;
  }
  call_out("trouble",1,--index);
  return 1;
}

