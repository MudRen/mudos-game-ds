#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;
varargs int receive_damage(string type, int damage, object who);
void normal_ai();
void combat_ai();

mapping *combat_action = ({
        ([  "action":       "$N平舉丙子觀林劍，喊道：引氣御劍術！\n"
                            "丙子觀林劍居然飄離貓婆婆手中凌空飛起，直直插向$n的$l！",
                "attact_type":  "bio",
                "damage_type":  "刺傷",
        ]),
        ([  "action":       "$N凌空躍起，兩足站在丙子觀林劍的劍刃上，喊道：雪崩斬落劍！\n"
                            "丙子觀林劍夾帶下落之勢重重斬向$n的$l！",
                "attact_type":  "bar",
                "damage_type":  "砍傷",
        ]),
        ([  "action":       "$N將丙子觀林劍拋向半空，結印喊道：以心鳴雷劍！\n"
                            "空中一道閃電受到丙子觀林劍的導引，擊向$n所站的位置。",
                "attact_type":  "wit",
                "damage_type":  "電擊傷",
        ]),
        ([  "action":       "$N緩緩以劍刃凌空畫圓，口中喃喃唸咒，\n"
                            "$n嚇然見到無數毒蛇從劍圈中竄出，朝自己狂噬而來！",
                "attact_type":  "sou",
                "damage_type":  "咬傷",
        ]),
        ([  "action":       "$N拋出丙子觀林劍，雙手結印指向$n，\n"
                            "丙子觀林劍瞬即如旋風般疾速在$n的身上切割。",
                "attact_type":  "tec",
                "damage_type":  "多處割傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name("貓婆婆", ({"cat oldwoman","oldwoman","_CAT_OLDWOMAN_"}));
  set("long",@long
曲著身子，皮膚又乾又皺，正拿著木棍攪動面前大鍋內的液體，她的
腰間佩著一把看起來很華麗的長劍，嘴巴不時喃喃的不知道唸著什麼
。
long);      
  set("gender", "女性" );
  set("age",193);
  set("evil",50);
  set("level",50);
  set("attitude", "aggressive");
    set("race","celestial");
    set("race","celestial");
  set("con",109);
  set("int",100);
  set("dex",80);
  set_skill("sword", 90);
  set_skill("parry", 70);
  set_skill("dodge", 70);
  set_skill("unarmed", 70);
  set_temp("apply/hit",40);
  set_temp("apply/dodge",30);
  add("addition_armor",130+random(5));
  set("talk_reply","敢來壞我的好事，找死！！\n");
  set("chat_chance", 80);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",200);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  set("can_defend", 1);
  setup();
  set_living_name("_NPC_CAT_OLDWOMAN_");
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object(__DIR__"eq/cat-tail-waist")->wear();
  add_money("coin",2000);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("apeman-enemy") ) this_object()->kill_ob(this_player());
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

void normal_ai()
{
  object me,target;
  me = this_object();
  target = this_player();

  if(me->is_busy()) return;
  if( me->query("hp") + 200 < me->query("max_hp") )
  {
    message_vision(HIG"\n$N雙手合掌結印，同時念念有詞，$N身上的傷口居然漸漸癒合！\n\n"NOR,me);
    me->receive_heal("hp",300);
    me->start_busy(3);
    return;
  }

  if( me->query("mp") + 200 < me->query("max_mp") )
  {
    message_vision(HIG"\n$N從大鍋中勺了一點液體飲下，精神看來好了許\多。\n\n"NOR,me);
    me->receive_heal("mp",300);
    me->start_busy(3);
    return;
  }

  switch( random(25) )
  {
     case  0: message_vision("貓婆婆喃喃唸道：這鍋藥製好後，就能讓山崽們對村莊發動攻擊了，嘿嘿嘿．．．\n",me);
           break;
     case  1: message_vision("貓婆婆喃喃唸道：出雲山危險重重，還是入冬再進去較安全。\n",me);
           break;
     case  2: message_vision("貓婆婆一邊攪動鍋子，好像想得出神似的，沒有注意到你的存在。\n",me);
           break;
     case  3: message_vision("貓婆婆喃喃唸道：還差個東西放入(putting)就能完成這鍋藥了，\n"
                             "嗯．．叫山崽王去辦不知道能不能完成．．．\n",me);
           break;
  }
  return;
}

void combat_ai()
{
  int hp,mp,ap,max_hp,max_mp,max_ap;
  object b,ob1,ob2,ob3,ob4,me,target;
  me=this_object();
  target = offensive_target(me);
  ob1=find_living("_NPC_STONE_PUPPET_");
  ob2=find_living("_NPC_MUD_PUPPET_");
  ob3=find_living("_NPC_AXEMAN_");
  ob4=find_living("_NPC_PROTECT_GHOST_");
  hp=this_object()->query("hp");
  mp=this_object()->query("mp");
  ap=this_object()->query("ap");
  max_hp=this_object()->query("max_hp");
  max_mp=this_object()->query("max_mp");
  max_ap=this_object()->query("max_ap");

  if(me->is_busy()) return;
  if( objectp(ob1) )
  {
    if(!environment(ob1) )
    {
      destruct(ob1);
    }
  }
  else if( mp > 50 )
  {
    if(query_temp("wait_to_summon")) return;
    message_vision(HIW "\n$N將一張咒符貼在地面上，周圍的沙石竟以咒符為中心逐漸聚成人形！\n" NOR,me);
    b=new(__DIR__"stone-puppet" );
    b->move(environment(me));
    me->receive_damage("mp",50,me);
    me->start_busy(2);
    set_temp("wait_to_summon",1);
    call_out("delay",10);
    return;
  }

  if( objectp(ob2) )
  {
    if(!environment(ob2) )
    {
      destruct(ob2);
    }
  }
  else if( mp > 50 )
  {
    if(query_temp("wait_to_summon")) return;
    message_vision(HIW "\n$N將一張咒符貼在地面上，泥土迅速吸附在咒符上逐漸聚成人形！\n" NOR,me);
    b=new(__DIR__"mud-puppet" );
    b->move(environment(me));
    me->receive_damage("mp",50,me);
    me->start_busy(2);
    set_temp("wait_to_summon",1);
    call_out("delay",10);
    return;
  }

  if( objectp(ob3) )
  {
    if(!environment(ob3) )
    {
      destruct(ob3);
    }
  }
  else if( mp > 150 )
  {
    if(query_temp("wait_to_summon")) return;
    message_vision(HIR"\n$N咬破舌尖將鮮血噴在咒符上，瞬間四周陰氣凝聚，形成一名武者！\n" NOR,me);
    b=new(__DIR__"axeman" );
    b->move(environment(me));
    me->receive_damage("mp",150,me);
    me->start_busy(2);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }

  if( objectp(ob4) )
  {
    if(!environment(ob4) )
    {
      destruct(ob4);
    }
  }
  else if( mp > 150 )
  {
    if(query_temp("wait_to_summon")) return;
    message_vision(HIR"\n$N咬破舌尖將鮮血噴在咒符上，突然一道身影從地面浮現！\n" NOR,me);
    b=new(__DIR__"protect-ghost" );
    b->move(environment(me));
    me->receive_damage("mp",150,me);
    me->start_busy(2);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }

  if(!random(15))
  {
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
    COMBAT_D->report_statue(target);
    return;
  }
  return;
}

// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{
  if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
  if( type!="hp" && type!="mp" && type!="ap" )
      error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
  if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
  if(random(100)<30)
  {
    damage/=3;
    message_vision(HIM "\n$N及時使出替身術，身影突然變成一截木頭，閃開了直接的攻擊。\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}

void delay()
{
  delete_temp("wait_to_summon");
}

void die()
{
  object ob,ob1,ob2,ob3,ob4;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
  GRN"\n\t【鬼之森】："+HIM" 百年貓妖 "HIW" 被俠義心腸的"HIY+ob->name(1)+HIW"消滅了，村民無不歡欣鼓舞。\n\n"+NOR
    ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIG"你得到 5 點聲望。"NOR);
  ob->set_temp("kill_cat",1);
  ob1=find_living("_NPC_STONE_PUPPET_");
  ob2=find_living("_NPC_MUD_PUPPET_");
  ob3=find_living("_NPC_AXEMAN_");
  ob4=find_living("_NPC_PROTECT_GHOST_");
  if( objectp(ob1) && environment(ob1) )  destruct(ob1);
  if( objectp(ob2) && environment(ob2) )  destruct(ob2);
  if( objectp(ob3) && environment(ob3) )  destruct(ob3);
  if( objectp(ob4) && environment(ob4) )  destruct(ob4);
  
  if( random(5000) )
     new(__DIR__"eq/shi-ganrin-sword")->move(this_object());
  else
     new(__DIR__"eq/devil-cat-mask")->move(this_object());
  ::die();
  return;
}
