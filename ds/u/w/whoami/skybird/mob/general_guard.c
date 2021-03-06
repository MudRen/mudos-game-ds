#include <ansi.h>
#include <combat.h>
inherit NPC;
void kill_ian();

void create()
{
        set_name( "將軍護衛", ({"general guard", "general", "guard"}) );
        set("long", @LONG 
這人相貌質樸，但是雙目寒光四射，一雙手掌又寬又大，指節突
出，虯筋糾結，必然是修煉外功之人，而他行動之間卻是點塵不
驚，可見火候已經到了爐火純青的地步，再看這人周身上下殺氣
隱隱，身姿挺拔，這一定是久在軍中的勇士，讓這樣的人做區區
的侍衛，可見皇上對奉國將軍的看重。
LONG);
        set("title", HIY"四品虎"NOR);
        set("gender", "男姓");
        set("race", "人類");
        set("age", 15+random(20));
        set("level",50+random(5));
        set("str",85+random(20));
        set("Merits/bar",4+random(2));  
        set("Merits/wit",7+random(2)); 
        set_temp("apply/damage",85+random(30));  
        set_temp("apply/armor",75+random(30)); 
        set_temp("apply/hit",75+random(30));
        set_skill("dodge", 80+random(10));
        set_skill("parry", 80+random(20));
        set_skill("unarmed", 80+random(30));
        set_skill("sword", 90+random(20));
        set_skill("berserk",60+random(51)); 
        set_temp("soldier",1);        setup();
        set_living_name("General_guard");
        carry_object("/open/world1/acme/cominging/npc/wp/sword")->wield();
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
            if( target[x]->query_temp("soldier") ) continue;            command("say 不想活了！？竟敢在軍營內打鬥！！");
            ob->kill_ob(target[x]);
            me->kill_ob(ob);
        }
}

void guard()
{ 
           this_object()->set_temp("summon",1);
           command("defend fenq-gwo general");
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
  command("wield sword");
  return 0;
  }
  wp = me->query_temp("weapon");
  if(me->query("ap") < 150) return 0;
  addbar = tbar - mybar + 1;
  damage =  mysk * (myint/20);  if( !random(4) )
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

  return 0;}

int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        
        if( is_fighting(me) ) return 0;
        command("snort");
        command("say 去死吧！！");

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
        object ob;        
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                destruct(this_object());
                return;
        } 
        
        if( this_object()->query_temp("summon") ){
            command("say 你等等，我去拿把武器再來•");
            command("west");
            destruct(this_object());
        } else {
        ::die();
        }
        return;
}


