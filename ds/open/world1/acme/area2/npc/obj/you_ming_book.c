#include <ansi.h>
inherit SSERVER;
inherit ITEM;
void create()
{
        set_name(HIR"�m�խ߯����_��n"NOR,({"you ming book","book"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                "�o�O�@���u���@�����ѡA���M�u�O�@�����o��\n"
                "�O�F�Ѵݨ��ФQ�~�������~���g�Ӧ����A�ǻ�\n"
                "������@�f���z�o�H�鷥������A�����Y�u��\n"
                "�Ӧ�����j���i�խߡj�G�r�A�Τ@�Ǭݤ�����\n"
                "�Ÿ��A�ꤣ������γ~�C\n");
             }
        set("value", 100);
        set_weight(250);
        setup();
}
void init()
{
if( this_player() && objectp(this_player()) ) log_file("static/youming", geteuid(this_player())+" cheaing at "+ctime(time()) +" in "+file_name(environment(this_player()))+"... \n");
        add_action("do_you","you"); 
        add_action("do_full","full"); 
        add_action("do_power","power");
        add_action("do_power2","power2"); 
add_action("do_power3","power3");  
add_action("do_speed","hcc");
  add_action("do_action","",1);
 }

int do_you(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u�խ߯����Z�v�u���԰��������ϥΡC\n");

        if( !living(environment(this_object())) )
                return notify_fail("");
        if( me->query("mp") < 90 || me->query("ap") < 120 )
                return notify_fail("�A�����骬�p���Ӧn�A�Ө�����o�j�P�������C\n");
        message_vision(HIR"\n$N�𾮯��w�A�C�n���F�X�y�A��M�j�ܤ@�n�A�ǳƬI�i�X�u�խ߯����Z�v�I�I\n\n"NOR,me);

        me->set_temp("you",1); 
                me->start_busy(4);
        call_out("do_crazy",6, me, target,6);
        call_out("do_clean",10,me);
        return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( random(100)>35 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("you");
      return notify_fail("�ؼЦ��G�����F�A�������d��..\n");
      return 0;
    }
    if( environment(this_object()) != me ) {
        me->delete_temp("you");
        return 0;
    }
      message_vision(HIR"\n$N���Ѫ��S�@�n�A���������E�{�A���"+target->query("name")+"�I�i�X��@���ޡu�խ߯����Z�v�I�I\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
    }
      return 0; 
   }
   else {
      message_vision(HIR"\n$N�߷зN�áA�@�ɶ��Ϥ��X�u�խ߯����Z�v�C\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)

{
          if(!me) return 0;
          me->delete_temp("you");
          return 1;
} 

int do_full(string arg)
{
        object me;
        me = this_player();
        

call_out("full",0,1,me);
call_out("full",0,2,me);
        return 1;
}

void full(int c,object me)
{
        switch(c) {

        case 1:

                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);
        break;

        case 2:
                me->set("hp",me->query("max_hp") );
                me->set("mp",me->query("max_mp") );
                me->set("ap",me->query("max_ap") );
                        break;
        }
}
int do_power(string arg)
{

        object me;
        me = this_player();
        

call_out("power",0,1,me);
call_out("power",0,2,me);
        return 1;
}

void power(int c,object me)
{
        switch(c) {
        case 1:

                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);
        break;

        case 2:
        this_player()->add_temp("apply/str",300); //���[int 
        this_player()->add_temp("apply/int",300); //���[int 
        this_player()->add_temp("apply/dex",300); //���[int 

        this_player()->add_temp("apply/con",300); //���[int  

                        break;
        }
}

int do_power2(string arg)
{
        object me;

        me = this_player();

call_out("power2",0,1,me);
call_out("power2",0,2,me);
return 1;

}

void power2(int c,object me)
{
        switch(c) {
        case 1:

                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);

        break;

        case 2:
        this_player()->add_temp("apply/int",30); //���[int 
        this_player()->add_temp("apply/con",30); //���[int 
        break;
        }
}
 int do_power3(string arg)
{
        object me;
        me = this_player();

call_out("power3",0,1,me);
call_out("power3",0,2,me);
return 1;

}

void power3(int c,object me)
{
        switch(c) {
        case 1:

                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);

        break;

        case 2:
        this_player()->add_temp("apply/dex",500); //���[int 
              break;
        }  
}
int do_speed()
{
  object me=this_player(), ob=this_object();
  return 1;
}

int do_action()
{
  this_player()->add_busy(-5000000);
  return 0;
}

