#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
    set_name("�j��",({"well"}));
    set("unit", "�f");
    set("long",@LONG
    �ݰ_�ӫD�`���ª������A�Q�����۷����v�C�o�f���`�������A
�T�M�U�h���G���O�������|�A�ݨӱo��ӪF���k��(climb)�U�h�F�C
LONG);
    set_weight(99999);
    set("value", 1);
    set("no_sac", 1);
    set("no_get", 1);
    set("no_clean_up",1);
    setup();
}

void init()
{       
    add_action("do_climb","climb");
}

int do_climb(string arg)
{
    int sk;
    object me,obj,item;
    me = this_player();

    if(me->is_busy())
       return notify_fail("�A���b���C\n");
    if(!arg || sscanf(arg, "into %s", arg) != 1)
       return notify_fail("�A�n�k���i(climb into)���̡H\n");
    if(arg != "well" && arg != "�j��")
       return notify_fail("�A�n���i���̡H\n");
    if(!(item = present("rope",me)))
       return notify_fail("�A�S���A�X���u���k���C\n");

    message_vision(HIC"$N�N��÷�T�w��K��۳�÷�ǳ��D�U�j��\n"NOR,me);
    destruct(item);
    call_out("msg",4,me);
    return 1;
}
int msg(object me)
{
    int i;
    i = me->query("str");
    switch(i/10+(random(5)+1))
    {
       case 1..6:
            message_vision(HIR"$N��M���Ϥ��W�O�P�}�F��A�Y�J�����I\n"NOR,me);
            me->receive_damage("hp",me->query("max_hp")/2);
            me->receive_wound("random",random(10)+1,me);
            me->start_busy(2);
            me->move("/u/f/fedex/fantasyland/room1");
            call_out("damage",0,me);
            break;
       case 7..10:
            message_vision(HIR"$N��M���Ϥ��W�O�P�}�F��A�ҩ��w�g�֨줫���u���I���ˡC\n"NOR,me);
            me->receive_damage("hp",random(100)+1);
            me->start_busy(2);
            me->move("/u/f/fedex/fantasyland/room1");
            call_out("damage",0,me);
            break;
       default:
            me->move("/u/f/fedex/fantasyland/room1");
            message_vision(HIR"$Níí���۳��b�����C\n"NOR,me);
            break;
    }
    return 1;
}

int damage(object me)
{
  int dam;
  string msg;
  object *list;
  list = all_inventory(environment(me));
  dam = random(300+1);

  if(!list) return 1;
  foreach(object who in list)
  {
     if(who == me) continue;
     if(environment(who) && userp(who))  
     {
          tell_object(who,HIW+me->query("name")+"�q���f���U�����b�A���W...\n"NOR);
          tell_object(who,HIR"[�A����"+dam+"�I���ˮ`]�C\n"NOR);
          tell_object(me,HIW"�A���������b"+who->name()+"���W...\n"NOR);
          who->receive_damage("hp",dam);
          who->start_busy(2);
     }
  }
  return 1;
}
