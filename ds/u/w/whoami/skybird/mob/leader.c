#include <ansi.h>
#include <combat.h>
inherit NPC;

string stone(object me);

void create()
{
        set_name( "輕車都尉", ({"leader"}) );
        set("long", @LONG
此人為從數千人中挑選出來的精銳戰士，為特殊戰鬥部隊的一員。
LONG    );

        set("title", HIY"武六品彪"NOR);
        set("gender", "男姓");
        set("race", "人類");
        set("age", 10+random(20));
        set("level",45+random(15));
        set("Merits/bar",1+random(5)); 
        set_skill("dodge", 80+random(10));
        set_skill("parry", 80+random(20));
        set_skill("unarmed", 70+random(30));
        set_skill("berserk", 80+random(21));
        set("chat_chance",8);
        set("chat_msg", ({
         (: random_move :),
           }));                  
        set_temp("soldier",1);
        setup();
        set_living_name("Ten-mount_soldier");
        carry_object(__DIR__"wp/blade.c")->wield();
        carry_object(__DIR__"eq/huge_armor.c")->wear();
}

void init()
{ 
        object me=this_player(),ob=this_object(),*target;
        int x;
        target = all_inventory(environment(ob));   
        add_action("do_kill","kill");
        for(x=0;x<sizeof(target);x++){
            if( !target[x]->is_fighting() ) continue; 
            if( target[x]->query_temp("soldier") ) continue;
            if( ob->query_temp("protect") ) continue;
            command("say 不想活了！？竟敢在軍營內打鬥！！");
            ob->kill_ob(target[x]);
            me->kill_ob(ob);
        }
if( !ob->query_temp("auto_kill") || me->query_temp("soldier") ) return;   
        me->kill_ob(ob);
        ob->kill_ob(me);  
return;

}

int special_attack(object me, object target, int hitchance)
{
  object wp;
  int mysk = me->query_skill("berserk"),
      myint = me->query("int"),
      mybar = me->query("Merits/bar"),
      mydex = me->query("dex"),
      mylv = me->query("level"),
      tbar = target->query("Merits/bar"),
      bk1,bk,damage,addbar;
  if(me->query_temp("attacking")) return 0;
  if(!me) return 0;
  if(me->is_busy()) return 0; 
  if(!me->query_temp("weapon")) {
    command("wield blade");
  return 0;
  }
  wp = me->query_temp("weapon");
  if(me->query("ap") < 150) return 0;  addbar = tbar - mybar + 1;
  damage =  mysk * (myint/20);

  if( !random(4) )
  {
    me->add_temp("attacking",1);
    me->start_busy(random(3));
    message_vision("\n$N"HIR"雙眼發紅，全身青筋爆露，握緊手上"+wp->query("name")+HIR"便朝$n"HIR"一陣狂揮猛攻！！！！\n\n"NOR, me, target);
    me->add_temp("apply/damage", damage);
    if( mybar < tbar ){
    me->add_temp("apply/bar",addbar);
    me->set_temp("addbar",1);
    }   
    bk1=mysk/20+mydex/30-mybar/5; 
    if(bk1>5) bk1=6;
    for (bk=0;bk<bk1;bk++)
    {
     COMBAT_D->do_attack(me,target,wp,4);
     COMBAT_D->report_statue(target);
     me->receive_damage("ap",mysk/5);
    }
    if( me->query_temp("addbar") ){
    me->add_temp("apply/bar",-addbar); 
    me->delete_temp("addbar");
    }
    me->add_temp("apply/damage", -damage);
    me->delete_temp("attacking");
    return 1;
  }
  return 0;
}

int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        
        if( is_fighting(me) ) return 0;
        command("snort");
        command("say 去死吧！！ \n");

        ob=all_inventory(environment());
        for(i=0;i<sizeof(ob);i++)
        {
                ob[i]->soldier_assist(this_object(), me);
        }
        return 1;
}

void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
        ||      is_fighting(me) )
                return;

        switch(random(2)) {
        case 0: command("say 大膽！受死吧！\n"); break;
        case 1: command("say 看來你也是山賊一夥的！殺！！\n"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}

void die()
{
        object me=this_player(),ob=this_object();
                if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        if( this_object()->query_temp("auto_kill") && random(4) == 1 ){
        ob->add("popularity",2); 
        tell_object(ob,HIW"\n(因為你殺死了"+this_object()->query("name")+HIW"，所以得到了 2 點聲望。)\n"NOR); 
        }
        ::die();
        return;
}
