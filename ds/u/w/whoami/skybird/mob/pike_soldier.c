#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
        set_name( "�j��", ({"pike soldier", "pike", "soldier"}) );
        set("long", @LONG
���H���q�Ƥd�H���D��X�Ӫ���U�Ԥh�A���S��԰��������@���C
LONG);

        set("title", HIY"��U����"NOR);
        set("gender", "�k�m");
        set("race", "�H��");
        set("age", 10+random(20));
        set("level",35+random(15));
        set("Merits/bar",5+random(4)); 
        set("int",70+random(15));
        set_skill("dodge", 70+random(10));
        set_skill("parry", 70+random(20));
        set_skill("unarmed", 70+random(30));
        set_skill("fork", 80+random(21)); 
        set_skill("berserk", 100);
        set("chat_chance",8);
        set("chat_msg", ({
         (: random_move :),
           }));
        set_temp("soldier",1);                  
        setup();
        set_living_name("Ten-mount_soldier");
        carry_object(__DIR__"wp/pike3.c")->wield();
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
            command("say ���Q���F�I�H�����b�x�示�����I�I");
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
  command("wield halbert");
  return 0;
  }
  wp = me->query_temp("weapon");
  if(me->query("ap") < 150) return 0;  addbar = tbar - mybar + 1;
  damage =  mysk * (myint/20);  if( !random(4) )
  {
    me->add_temp("attacking",1);
    me->start_busy(random(3));
    message_vision("\n$N"HIR"�����o���A�����C���z�S�A�����W"+wp->query("name")+HIR"�K��$n"HIR"�@�}�g���r��I�I�I�I\n\n"NOR, me, target);
    me->add_temp("apply/damage", damage);
    if( mybar < tbar ){
    me->add_temp("apply/bar",addbar);
    me->set_temp("addbar",1);
    }   
    bk1=mysk/20+mydex/30-mybar/5; 
    if(bk1>5) bk1=5;
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
 
        if(this_object()->query_temp("protect")) return 0;
        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        
        if( is_fighting(me) ) return 0;
        command("snort");
        command("say �h���a�I�I \n");

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
        case 0: command("say �j�x�I�����a�I\n"); break;
        case 1: command("say �ݨӧA�]�O�s��@�٪��I���I�I\n"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}

void guard()
{
        object me,ob=this_object(),env,env1;
        me = find_player(ob->query_temp("protect"));
        env = environment(me);
        env1 = environment(ob);
        if( !me ){
            command("say �ǤF..�䤣��H..");
            destruct(this_object());
        } else {            
        if( env != env1 ) {
            ob->move(env);
            message_vision("$N��榣�����Ӧ����a�E\n",ob);
            command("say �����ڧr..");
        }
        if( me->is_fighting() && !ob->is_fighting() ) {
            command("defend "+ob->query_temp("protect"));
        }
        this_object()->delete("chat_chance");
        this_object()->set_leader(me);
     
        call_out("guard",10,ob);        
        }
return;
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
        tell_object(ob,HIW"\n(�]���A�����F"+this_object()->query("name")+HIW"�A�ҥH�o��F 2 �I�n��C)\n"NOR); 
        }
        ::die();
        return;
}
