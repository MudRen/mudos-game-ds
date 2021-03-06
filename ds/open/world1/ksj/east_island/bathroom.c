#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "大澡堂");
  set("long", @LONG
這裡是個蠻大的溫泉澡堂，整個澡堂使用木板搭建，旁邊有個櫃
台，大浴池中是熱騰騰的溫泉，對於消除疲勞療傷止痛非常有效，你
可以在放鬆心情在這理享受泡湯的樂趣(spa)。
LONG
);
  set("exits", ([
      "out" : __DIR__"room17",
               ]));
  set("light", 1);
  set("no_fight", 1);
  set("no_cast", 1);
  set("no_exert", 1);
  set("no_clean_up", 0);
   set("objects",([
      __DIR__"npc/eq/bath-pool":1,
     ]) );
  setup();
}

void init()
{
  add_action("do_spa","spa");
}

int do_spa()
{
  object me;
  me=this_player();
  if( me->query_temp("bathe") <= 0 )
  {
    write("你所能泡湯的次數已用光了！\n");
    return 1;
  }

  if(me->query_temp("is_busy/washing"))
  {
    write("你正在舒服地泡湯中。\n");
    return 1;
  }
  message_vision(HIW "$N很快地換上了浴衣，拿了盥洗用具往大浴池走了過去。\n\n" NOR, me);
  tell_object(me, HIW "你慢慢地走進浴池坐了下去，呼∼∼真是舒服阿。\n\n" NOR );
  tell_object(me, HIB "你將毛巾折好覆蓋\在頭上，閉著雙眼全身放鬆地半躺著。\n\n\n" NOR );
  me->disable_player_cmds("你正在舒服地泡湯。\n");
  me->set_temp("is_busy/washing","你正在舒服地泡湯。");
  me->start_busy(10);
  call_out("wash1",3,me);
  call_out("wash2",8,me);
  call_out("wakeup",15,me);
  return 1;
}

void wash1(object me)
{
  if(!me) return;
  tell_object(me,HIG"你只覺得身心毫無負擔，彷彿進入無憂無慮的世界∼\n"NOR);
  me->receive_heal("hp",me->query_con()*4);
  me->receive_heal("ap",me->query_con()*2);
  me->receive_heal("mp",me->query_int()*3);
  return;
}

void wash2(object me)
{
  if(!me) return;
  switch( random(4))
  {
     case 0:
          tell_object(me,HIG"你的眼前浮現了一片草原，草原上群蝶飛舞，微風吹拂∼∼\n"NOR);
          break;
     case 1:
          tell_object(me,HIW"你的眼前出現了許\多神兵利器，你高興地一一拿起來揮舞∼∼\n"NOR);
          break;
     case 2:
          tell_object(me,HIM"你的眼前浮現了間古老的密室，密室的四周竟然全都是武林絕學∼∼\n"NOR);
          break;
     case 3:
          tell_object(me,HIY"你的眼前浮現了一座金碧輝煌的宮殿，你正坐在王座上接受群臣的朝拜∼∼\n"NOR);
          break;
  }
  me->receive_heal("hp",me->query_con()*5);
  return;
}

void wakeup(object me)
{
  if(!me) return;
  message_vision(HIW"$N突然被旁邊的客人碰了一下，揉了揉眼睛醒了過來。\n" NOR,me);
  me->enable_player_cmds();
  me->delete_temp("is_busy/washing");
  me->receive_heal("hp",me->query_con()*7);
  me->receive_heal("mp",me->query_int()*3);
  me->receive_heal("ap",me->query_con()*3);
  me->add_temp("bathe",-1);
  return;
}
