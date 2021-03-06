#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","密林入口");
 set("long",@LONG
這裡是一處密林的入口, 四周的光線相當昏暗, 只有往離開的方向
的光線尚稱明亮. 你在這裡停頓了一下, 發現前方密林過於茂盛, 你甚
至無法發現可以從哪裡進去這片密林, 但你可在附近仔細找找(search).
這邊有個標語(sign). 你最好先仔細的看看上面在寫什麼.
LONG);

 set("exits",([ "south":__DIR__"road4",]));
 set("item_desc",([
     "小空隙":"你找了老大半天, 總算看到個小小的空隙似乎可以讓\n
你鑽(squeeze)進去密林之中。\n",
     "標語":"標語上寫著: 此處危險! 請結伴同行...! 勿攜帶發光物..! 注意!\n",
        "sign":"標語上寫著: 此處危險! 請結伴同行...! 勿攜帶發光物..! 注意!\n",
]));
               
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
}
void init()
{
  add_action("do_squeeze","squeeze");
  add_action("do_pick","pick");
}
int do_squeeze(string arg)
{
  object me;
  me=this_player();
  if(!arg) return notify_fail("你要鑽進哪裡 ?\n");
  if( arg != "小空隙" && arg != "空隙")
    return notify_fail("這個地方有空間讓你鑽進去嗎 ?\n");
  message_vision("$N縮著身子硬是擠進了這片密林中.\n",me);
  me->start_busy(2);
  me->move(__DIR__"forest2");
  return 1;
}

void clear_pick() {
        set("picked",0);
}

int do_pick(string arg)
{
  object me,key;
  if( !query("active_action") ) return 0;
  if( query("picked") ) return 0;

  me=this_player();
  if( me->is_fighting() || me->is_busy() ) return notify_fail("你正在忙耶!\n");
  if( !arg || ( arg != "key" && arg != "鑰匙" ) ) return notify_fail("你要撿什麼?\n");

  key = new(__DIR__"npc/obj/greenkey");
  message_vision(HIB"$N突然從草叢間找出了一把鑰匙!\n"NOR,me);
  key->move(me);
  set("picked",1);
  add("item_desc",([ "看起來怪怪的草堆":"這草堆又沒什麼好看的..\n" ]));
  call_out("clear_pick", 600 + random(150) );
  return 1;
}

