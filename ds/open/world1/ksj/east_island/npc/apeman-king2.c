#include <ansi.h>
#include <combat.h>     
inherit NPC;
object z;
int i;

void create()
{
  set_name("山崽王", ({"apeman king","king"}) );
  set("long",@LONG
體形巨大的山崽，直立時有三公尺高，長長的獠牙露出在嘴巴外，全
身肌肉凸出，遠遠看就覺得很恐怖，牠的全身佈滿大大小小的傷疤。
LONG);
  set("race", "人類");
  set("unit","隻");
  set("age",50);
  set("evil",30);
  set("gender", "男性" );
  set("level",45);
  set("int",30);
  set("str",115);
  set("con",140);
  set("dex",70);
  set_skill("unarmed",70);
  set_skill("dodge",20);
  set_skill("parry",40);
  add("addition_damage",50);
  add("addition_armor",100);
  setup();
  carry_object(__DIR__"eq/bone-armor")->wear();
  carry_object(__DIR__"eq/wrists-design-page");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( objectp(z=present("shi-ganrin sword",this_player())) )
  {  
    message_vision("$N看到$n身上的丙子觀林劍，竟乖乖伏首聽令(hest)。\n",this_object(),this_player() );
    i=this_player()->query_temp("hest_king_times");
    this_player()->set_temp("hest_king_times",i+1);
    this_object()->set("creater",this_player());         
    this_object()->set_leader(this_player());
    this_object()->set_temp("last_opponent",0);
    this_object()->remove_all_killer();
    if( this_player()->query_temp("hest_king_times") > 7 )
    {
      call_out("crazy",0,this_player());
      return;
    }
    call_out("crazy",30,this_player());
    return;
  }
  if( userp(this_player()) && this_object()->query("creater")!=this_player() )
     this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4))
  {
    message_vision( "$N雙眼通紅，發出一陣怒吼。\n", this_object() );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void crazy(object ob)
{
  object env;
  env = environment(this_object());
  if( env != environment(ob) ) return;
  if( userp(ob) && objectp(z=present("shi-ganrin sword",ob)) )
  {
    message_vision(HIR"山崽王察覺不對勁，奪去$N身上的丙子觀林劍遠遠地扔掉。\n"NOR,ob );
    this_object()->kill_ob(ob);
    destruct(z);
    this_object()->delete("creater");
    this_object()->set_leader(0);
    this_player()->delete_temp("hest_king_times");
    return;
  }
  return;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob->add("popularity",2);      
  tell_object(ob,HIG"你得到 2 點聲望。"NOR);
  ::die();
  return;
}
