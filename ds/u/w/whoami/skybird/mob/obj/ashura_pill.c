#include <ansi.h>
inherit ITEM;
void create()
{ 
  set_name(HIR"��ù�Y"NOR, ({ "ashura pill","pill" }));
  set("long","�@���_�S�����ġA�A�Pı����o���ĩҴ��o�X�����M�`�𮧡E\n");
  set_weight(80); 
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",30000);
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        string type,msg;
        object ob,me,env,*target; 
        int x;
        me = this_player();
        ob = this_object();
        target = all_inventory(environment(me));
        if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
        if( me->is_busy() )
                return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
        if( ob->query("do_eat") )
                return notify_fail("�A�w�g�t�b�L�̤F�C\n");
        if(me->query_temp("super_used") )
                return notify_fail("�A�L�̥��t�۪F��A����A��F��i�h�F�C\n");

        if( me->is_fighting() ) me->start_busy(2);
        message_vision(HIR "$N�q�h�����X�F�@������⪺�ĤY, �H�Y��J�f���t�ۡE\n" NOR,me);
        if( me->query("MKS") < 50000 )
        {
                tell_object(me,RED"�A�����z���A�@�ѷQ���H���N���ĤF�W�ӡI�I\n" NOR);
                message_vision(HIR "$N���S�����A�����ۦb�����Ҧ��ͪ��K�K\n" NOR,me);
                me->add("MKS",1000);
                me->add("pill/MKS",1000);
                ob->set_temp("times",me->query("level")); 
                call_out("aggressive",5);
                for(x;x<sizeof(target);x++){  
                    if(target[x] == me) continue; 
                    if( !living(target[x]))continue; 
                    if( target[x]->is_fighting(me) )continue; 
                    message_vision(HIY"$N���F$n�@����A��M���$n�ۨ�G���a�I�I\n"NOR,me,target[x]);
                    me->kill_ob(target[x]);
                    target[x]->kill_ob(me);
                } 
                me->add_temp("super_used",1);
                  ob->set_temp("invis",1);
                ob->set("super_used",1);
                return 1;      
        } 

        if(!ob->query("super_used") && !me->query_temp("super_used") )
        {
                tell_object(me,HIY"�A�P�즳�ѱj�P������q�ĤY�����F�X�ӡI�I\n"NOR);
                message_vision(HIC"$N�������B�Τ��O�N�Ĥ��������ഫ���ۨ��u��K�K\n" NOR,me);
                me->add_temp("apply/bar",1);
                me->add_temp("apply/wit",1);
                me->add_temp("apply/sou",1);
                me->add_temp("apply/tec",1);
                me->add_temp("apply/bio",1);
                me->add_temp("apply/dex",5);
                me->add_temp("apply/str",5); 
                me->add_temp("apply/con",5);
                me->add_temp("apply/int",5); 
                me->add_temp("apply/damage",50);
                me->add_temp("super_used",1);
                ob->set("super_used",1);
                ob->set("do_eat",1);
                ob->set("no_drop",1);
                ob->set("no_sac",1);
                ob->set("no_give",1);
                ob->set("no_sell",1); 
                ob->set_temp("invis",1);
                call_out("delay",me->query("level")*3,me);     //���[�ݩʺ����ɶ�
        }
        return 1;
}


void delay(object me)
{
        if(!me) return;
        message_vision(HIG"��¶�b$N�P�D�����𺥺��A���K�K\n" NOR,me);
        me->add_temp("apply/str",-5);
        me->add_temp("apply/dex",-5); 
        me->add_temp("apply/int",-5);
        me->add_temp("apply/con",-5);
        me->add_temp("apply/bar",-1);
        me->add_temp("apply/wit",-1);
        me->add_temp("apply/sou",-1);
        me->add_temp("apply/tec",-1);
        me->add_temp("apply/bio",-1); 
        me->add_temp("apply/damage",-50);
        me->delete_temp("super_used");
        destruct(this_object());
}

void aggressive()
{
        object ob,me,env,*target; 
        int x;
        me = this_player();
        ob = this_object(); 
        target = all_inventory(environment(me));
        if(!me) return;
          if( ob->query_temp("times") ){
                for(x;x<sizeof(target);x++){  
                    if(target[x] == me) continue;
                    if( !living(target[x]))continue; 
                    if( target[x]->is_fighting(me) )continue;
                    message_vision(HIY"$N���F$n�@����A��M���$n�ۨ�G���a�I�I\n"NOR,me,target[x]);
                    target[x]->kill_ob(me);
                }
          call_out("aggressive",5);
          ob->add_temp("times",-1);
          } else {
          message_vision(HIG"��¶�b$N�P�D�����𺥺��A���K�K\n" NOR,me);
          me->delete_temp("super_used");
          destruct(ob);
          }
        return;
}

