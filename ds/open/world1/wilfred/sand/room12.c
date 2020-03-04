#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIC"吃到飽客棧"NOR);
  set ("long", @LONG
這是鎮上唯一的客棧，店老闆豪邁熱情，作生意的方法也和別人
不同，只要是進來吃飯的客人，都可以盡情的吃到飽再走，東西相當
便宜，是相當為人津津樂道的小店。
LONG
);
  set("exits", ([
  "west" : __DIR__"room11",
]));
  set("objects",([
  __DIR__"npc/npc33" : 1,
  __DIR__"npc/npc32" : 1,
]));
  set("light",1);
  set("no_clean_up", 0);
  set("no_recall",1);
set("no_goto",1);
  set("valid_startroom", 1);
  setup();
}

void init()
{
  add_action("do_put","put");
  add_action("do_run","run");
}

int do_run()
{
  write("店小二對你說道：這位客倌，您還是出了店再用這個指令吧。\n");
  return 1;
}
int do_put()
{
  write("店小二對你說道：這位客倌，您還是出了店再用這個指令吧。\n");
  return 1;
}

int valid_leave(object me, string dir)
{
  int i, j=0;
  object *obs = deep_inventory(me);
  for(i=0; i<sizeof(obs); i++)
  {
    if(obs[i]->query("id") == "cheap leg"  ||
       obs[i]->query("id") == "cheap wine" ||
       obs[i]->query("id") == "cheap soup" )
    {
      message_vision("$N丟下一個$n。\n",me,obs[i]);
      destruct(obs[i]);
      j++;
    }
  }
  if(j) message_vision("店小二連忙把地上的東西收拾乾淨。\n",me);
  return ::valid_leave();
}
