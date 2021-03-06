#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "天機閣");
  set ("long", @LONG
古墓佔地極廣，殿閣亭臺，氣象肅森，依地勢而建，背靠山崗主
宮天機殿。古墓主殿高聳天際，秀出於群宮之上，使古墓主殿天機閣
雄視整個墓地，但令人百思不得其解的是，這座山相當滯礙難行，便
想鋪路也是大不可能，卻又如何能在此地建出如此雄偉建築？
LONG
);
  set("exits", ([
  "north" : __DIR__"room90",
  "south" : __DIR__"room88",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
//  replace_program(ROOM);
}

// 2003.4.10 新增阻擋功能 by ksj
int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("red-eye black dragon", this_object())) && dir == "north" && userp(me))
  {
    message_vision(HIW"當$N試圖從$n"HIW"的身旁通過時，被$n"HIW"狠狠的擋了回來！！\n"NOR,me,guard);
    write(HIG"[看來必需打倒牠了，否則別想通過這裡]\n"NOR);
    if(!random(4))
    {
      message_vision(HIR"$N大吼一聲，火紅的雙眼精光大盛，狠狠的朝著$n的頭就是一爪！！\n"NOR,guard,me);
      guard->kill_ob(me);
    }
    return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
