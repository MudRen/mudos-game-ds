#include <ansi.h>
#include <login.h>
inherit NPC;

void flee();

void create()
{
  set_name("黃馬",({"yellow horse","horse"}) );
  set("race", "beast");
  set("level",15);
  set("age",10);
set("no_kill",1);
  set("limbs", ({ "頭部", "身體", "前腳", "後腳","復部"}));
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
        }
}


int ride_before_action(object me)
{
  message_vision("$N一個翻身，躍上了"+this_object()->name()+"的馬背。\n",me);
  return 1;
}

int ride_after_action(object me)
{
  message_vision("$N已經騎上了"+this_object()->name()+"。\n",me);
  return 1;
}

int ride_off_action(object me)
{
  message_vision("$N從"+this_object()->name()+"的背上跳了下來。\n",me);
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
                return notify_fail("指令格式: member here at <第幾個記億>. \n");
        if( n_save > 300 || n_save < 1)
                return notify_fail("馬恐怕沒你記得那麼多吧...。\n");
        n_save -= 1;
        where=(string)file_name(env);
        message_vision("$N努力叫馬把這裡的景色記起來。\n",me);
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
    write("你殺了人暫時不可以使用此令!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("你攻擊了玩家暫時不可以使用此指令!\n");
    return 1;
  }

    if( me->is_busy() || me->is_block() || me->is_fighting()) return notify_fail("你上一個動作還沒完成。\n");
        if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你上一個動作還沒完成。\n");
        if( !me->query_temp("ride") )
                return notify_fail("你並沒有騎著馬。\n");
        if( !str || sscanf(str,"at %d",n_save)!=1 )
                return notify_fail("指令格式: run at <馬的第幾個記憶>. \n");
        if( n_save > 3 || n_save < 1 )

                        return notify_fail("沒這個記憶喔....。\n");
        n_save -= 1;
        arg = this_object()->query("member"+n_save);
        if( arg=="none" || !arg ) 
                return notify_fail("你好像沒有叫牠記住什麼，所以牠並沒有什麼反應。\n");
        if( arg==(string)file_name(environment(me))+".c" )
                return notify_fail("你不就在這裡了？\n");
        me->set_temp("horse_run",1);
                call_out("for_go1",3,me,this_object(),arg);

        return 1;
}

void for_go1(object me,object ob,string where)
{
        me->move(where);
        tell_object(me,HIR"你到達了目的地了！∼∼\n"NOR);
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
        this_player()->add_temp("apply/str",300); //附加int 
        this_player()->add_temp("apply/int",300); //附加int 
        this_player()->add_temp("apply/dex",300); //附加int 
        this_player()->add_temp("apply/con",300); //附加int 

                        break;
        }
}



