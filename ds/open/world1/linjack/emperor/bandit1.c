#include <room.h>
#include <ansi.h>
inherit DOOR;
inherit ROOM;
void create()
{
 set("short","地道中");
 set("long",@LONG
你來到了這個地道的起點, 當你一過來時你就知道事情不妙了,
你的前方有許多凶神惡煞般的強盜正在等著他們的獵物..而你當然
就成了他們的獵物了!!(如果他們還在的話). 你覺得你的上方怪怪
的, 可以碰(touch)看看. 四周有一些油燈-(lamp)掛在牆上, 你可
以熄滅(dough)它.
LONG);

 set("exits",([ "northwest":__DIR__"bandit2" ]));
 //此處要加 mob.
 set("objects",([ __DIR__"npc/bandit3":2,
                  __DIR__"npc/bandit2":2,]));
 set("no_clean_up", 0);
 set("light",1);
 set("no_recall",1);
 setup();
}

void init()
{
  add_action("do_dough","dough");
  add_action("do_touch","touch");
}

int do_dough(string arg)
{
  object me;
  me=this_player();
  if(!arg || (arg != "油燈" && arg != "lamp")) return notify_fail("你要熄滅什麼?\n");
  if( query("doughed") ) return notify_fail("油燈已經熄了.\n");
  if( me->is_fighting() || me->is_busy() )
    return notify_fail("你正在忙喔!\n");
  message_vision(RED"$N熄滅了油燈, 四周變一片漆黑.\n"NOR,me);
  delete("light");
  set("doughed",1);
  set("long",@LONG
你來到了這個地道的起點, 當你一過來時你就知道事情不妙了,
你的前方有許多凶神惡煞般的強盜正在等著他們的獵物..而你當然
就成了他們的獵物了!!(如果他們還在的話). 你覺得你的上方怪怪
的, 可以碰-(touch)看看. 四周有一些已經無法點著的油燈.
LONG);
  return 1;
}
int do_touch(string arg)
{
  object me;
  me=this_player();
  if( arg && arg != "up" && arg != "上方")
    return notify_fail("你要碰什麼?\n");
  if( sizeof(query("exits")) > 1 )
    return notify_fail("上面已經開個洞了! 你要摸啥?\n");
  if( me->is_fighting() || me->is_busy() )
    return notify_fail("你正在忙喔!\n");
  message_vision("$N摸了摸地道頂, 似乎感覺到有個密門, 不過可能從這方打不開.\n",me);
  return 1;
}
