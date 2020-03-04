#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("�ì^",({"coffin"}));
    set("unit", "��");
    set("long","���N�O�񦺤H���ç���....");
    set_weight(999999);
    set("value", 1);
    set("no_sac", 1);
    set("no_get", 1);
    set("no_clean_up",1);
    setup();
}

void init()
{       
    add_action("do_push","push");
}

int do_push(string arg)
{
   object me,obj;
   me = this_player();
   obj = this_object();

   if(arg != "�ì^" && arg != "coffin")
      return notify_fail("�A�n��ԣ�p�H\n");

   if(environment(obj)->query("coffin_ok") == 1)
   {
      /*-----�H���ʧ@���]-----*/
      message_vision(HIR"$N�ϫl�����}$n...\n"NOR,me,obj);
      call_out("open",3,me);
      return 1;
   }
   else
   { message_vision(HIR"$N�ϫl���Q���}$n�A�F...�٬O�����}���I\n"NOR,me,obj); }
  return 1;     
}

int open(object me)
{
  switch( random(20) ) 
  {
      case 0..10:
           message_vision(HIG"�ì^���Q�X�@�Ѯ���I\n"NOR,me);
//           me->apply_condition("poison", me->query_condition("poison")+random(10)+1);
           break;
      case 11..20:
           message_vision(HIY"�ì^���g�X�@���b�A$N�Q�{�׮ɫo�w�g�Q�b�g���C\n"NOR,me);
//           me->receive_wound("random",random(4)+1,me);
//           me->apply_condition("blooding",me->query_condition("blooding")+random(5)+1);
           break;
//      default:
//
//           break;
  }
  message_vision("�F...�i�H��BOX�F��H�I\n",me);
  environment(me)->delete("coffin_ok");
  "/u/f/fedex/area/room5"->add("exits",(["westdown" : "/u/f/fedex/area/room6"]));
  return 1;
}
