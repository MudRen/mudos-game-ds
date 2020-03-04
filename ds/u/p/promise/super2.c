#include <ansi.h>
#include <login.h>
inherit NPC;

void flee();

void create()
{
  set_name("����",({"yellow horse","horse"}) );
  set("race", "beast");
  set("level",15);
  set("age",10);
set("no_kill",1);
  set("limbs", ({ "�Y��", "����", "�e�}", "��}","�_��"}));
  set("verbs", ({"bite","hoof","crash"}));
  set("ridable",1);
  set("chat_chance_combat", 30);
  set("chat_msg_combat", ({ (: flee :) }));
  set("value", 700);
        set("chat_msg", ({
                (: random_move :),
        }));
  setup();
}
void init()
{
        ::init(); //luky
        add_action("do_name","name");
        if(environment(this_object())==this_player())
        {
          add_action("do_member","member");
          add_action("do_run","run");
          add_action("do_power","power");
          add_action("do_full","full");
          add_action("do_power2","power2");
        }
}


int ride_before_action(object me)
{
  message_vision("$N�@��½���A�D�W�F"+this_object()->name()+"�����I�C\n",me);
  return 1;
}

int ride_after_action(object me)
{
  message_vision("$N�w�g�M�W�F"+this_object()->name()+"�C\n",me);
  return 1;
}

int ride_off_action(object me)
{
  message_vision("$N�q"+this_object()->name()+"���I�W���F�U�ӡC\n",me);
  return 1;
}


int do_member(string arg)
{
        int n_save;
        string where;

        object me,env;
        me=this_player();
        if(! env = environment(me)) return 0;
        if( !arg || sscanf(arg,"here at %d",n_save)!=1 )
                return notify_fail("���O�榡: member here at <�ĴX�ӰO��>. \n");
        if( n_save > 300 || n_save < 1)
                return notify_fail("�����ȨS�A�O�o����h�a...�C\n");
        n_save -= 1;
        where=(string)file_name(env);
        message_vision("$N�V�O�s����o�̪�����O�_�ӡC\n",me);
        set("member"+n_save, where+".c");
        return 1;
}

int do_run(string str)
{
        int n_save;
        string arg;
        object me=this_player();
        if(!me) return 0;
   if(me->query_temp("killer"))
  {
    write("�A���F�H�Ȯɤ��i�H�ϥΦ��O!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("�A�����F���a�Ȯɤ��i�H�ϥΦ����O!\n");
    return 1;
  }

    if( me->is_busy() || me->is_block() || me->is_fighting()) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
        if( sizeof(me->query_temp("is_busy")) ) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
        if( !me->query_temp("ride") )
                return notify_fail("�A�èS���M�۰��C\n");
        if( !str || sscanf(str,"at %d",n_save)!=1 )
                return notify_fail("���O�榡: run at <�����ĴX�ӰO��>. \n");
        if( n_save > 3 || n_save < 1 )

                        return notify_fail("�S�o�ӰO�г�....�C\n");
        n_save -= 1;
        arg = this_object()->query("member"+n_save);
        if( arg=="none" || !arg ) 
                return notify_fail("�A�n���S���s�e�O����A�ҥH�e�èS����������C\n");
        if( arg==(string)file_name(environment(me))+".c" )
                return notify_fail("�A���N�b�o�̤F�H\n");
        me->set_temp("horse_run",1);
                call_out("for_go1",3,me,this_object(),arg);

        return 1;
}

void for_go1(object me,object ob,string where)
{
        me->move(where);
        tell_object(me,HIR"�A��F�F�ت��a�F�I���\n"NOR);
        ob->move(me);
        me->delete_temp("horse_run");
        return;
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


