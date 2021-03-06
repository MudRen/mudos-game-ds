
#include <ansi.h>
#define BASIC 3

  inherit SKILL;
  inherit SSERVER;

  int do_perform(object *obj);

  string *attck_msg = ({
          "$N一聲長嘯，接連八掌拍向$n！！\n",
  });

  string *start_msg = ({
       HIW   "位於天位的$N準備發動攻勢！！\n" NOR,
       HIY   "位於地位的$N準備發動攻勢！！\n" NOR,
       HIC   "位於人位的$N準備發動攻勢！！\n" NOR,
  });


  int form_array(object me)
  {
          int i,j;
          object *t,ob,env;
          object *ct=({});

  if(!me) me=this_player();
  //戰鬥型陣法
  //      if(!me->is_fighting() )
  //              return notify_fail("你並沒有在戰鬥，無法使用這個陣法。\n");

          if(me->is_busy() )
                  return notify_fail("你正忙著，沒空佈陣。\n");
          t=me->query_team();
          env=environment(me);

          //從team 中，找出可以使用陣法的人物
          //須嚴格在此設好條件。
          for (i=0;i<sizeof(t);i++)
          {
          ob=t[i];
          if( sizeof(ct)==BASIC ) break;
          if( !ob ) continue;
          if( ob->is_busy() ) continue;
          if( env != environment(ob) ) continue;

          /*
          if( !ob->is_fighting() ) continue;
          if( !ob->query_skill("seven-star") ) continue;
          if( ob->query("ap") < 200 || ob->query("hp") < 200 ) continue;
          */

          ct += ({ob});
  //          if(wizardp(me) ) write( ob->query("name")+"("+ob->query("id")+")\n");
          }

          if(sizeof(ct) < BASIC)  return notify_fail("你沒有足夠的隊友能使用這個陣法。\n");
          else                    do_perform(ct); //引發陣法
          return 1;
  }

  int do_perform(object *ct)
  {
          object ob,target;
            int i,damage,jj;

          target = offensive_target(ct[0]);
          if(!target)   
                  return notify_fail("你找不到敵人。\n");

          message_vision(HIG "\n$N往後跳出了戰圈，高聲長嘯：「佈『天地人三才陣』！！」\n" NOR,ct[0]);
          message_vision("$N等三人隨分站天、地、人三位！！\n",ct[0]);

            for(jj=0;jj<3;jj++)        {

                  for (i=0;i<sizeof(ct);i++)        {
                  ob=ct[i];       
                  message_vision(start_msg[i],ob);
                  if(!ob->can_fight(target) )     {
                  message_vision(CYN"$N身形一滯，整個陣法停了下來。\n"NOR,ob);
                  return 1;
                  }
                  ob->attack();
                  if(!ob->is_fighting(target) )
                          ob->kill_ob(target);
                  if(!target->is_fighting(ob) ) 
                          target->kill_ob(ob);
                  }       
          message_vision(CYN"$N長嘯一聲，陣法繼續驅動著！！\n"NOR,ct[0]);
          }
          return 1;
  }

