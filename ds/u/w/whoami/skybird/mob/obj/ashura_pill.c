#include <ansi.h>
inherit ITEM;
void create()
{ 
  set_name(HIR"修羅丸"NOR, ({ "ashura pill","pill" }));
  set("long","一顆奇特的妙藥，你感覺的到這顆藥所散發出的不尋常氣息•\n");
  set_weight(80); 
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
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
                return notify_fail("你上一個動作還沒有完成。\n");
        if( ob->query("do_eat") )
                return notify_fail("你已經含在嘴裡了。\n");
        if(me->query_temp("super_used") )
                return notify_fail("你嘴裡正含著東西，不能再塞東西進去了。\n");

        if( me->is_fighting() ) me->start_busy(2);
        message_vision(HIR "$N從懷中拿出了一顆血紅色的藥丸, 隨即放入口中含著•\n" NOR,me);
        if( me->query("MKS") < 50000 )
        {
                tell_object(me,RED"你雙眼爆紅，一股想殺人的意念衝了上來！！\n" NOR);
                message_vision(HIR "$N眼露兇光，掃視著在場的所有生物……\n" NOR,me);
                me->add("MKS",1000);
                me->add("pill/MKS",1000);
                ob->set_temp("times",me->query("level")); 
                call_out("aggressive",5);
                for(x;x<sizeof(target);x++){  
                    if(target[x] == me) continue; 
                    if( !living(target[x]))continue; 
                    if( target[x]->is_fighting(me) )continue; 
                    message_vision(HIY"$N瞪了$n一眼後，突然對著$n喊到：死吧！！\n"NOR,me,target[x]);
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
                tell_object(me,HIY"你感到有股強烈的殺氣從藥丸中散了出來！！\n"NOR);
                message_vision(HIC"$N巧妙的運用內力將藥中的殺氣轉換成自身真氣……\n" NOR,me);
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
                call_out("delay",me->query("level")*3,me);     //附加屬性維持時間
        }
        return 1;
}


void delay(object me)
{
        if(!me) return;
        message_vision(HIG"環繞在$N周遭的殺氣漸漸渙散……\n" NOR,me);
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
                    message_vision(HIY"$N瞪了$n一眼後，突然對著$n喊到：死吧！！\n"NOR,me,target[x]);
                    target[x]->kill_ob(me);
                }
          call_out("aggressive",5);
          ob->add_temp("times",-1);
          } else {
          message_vision(HIG"環繞在$N周遭的殺氣漸漸渙散……\n" NOR,me);
          me->delete_temp("super_used");
          destruct(ob);
          }
        return;
}

