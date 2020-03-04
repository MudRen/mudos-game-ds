#include <ansi.h> 
inherit NPC;   
void flee();  
void FG();
void create()
{
  set_name(HIY"轉龍"NOR, ({"turn dragon","dragon"}) );
  set("long","聖炎殿的守護獸，高大威猛，智商不比人類低，攻擊力強大。\n");
  set("race", "beast"); 
  set("title",HIG"地"NOR);
  set("unit","隻");
  set("age",80);
  set("level",70+random(this_player()->query("level")/5)); 
  set("max_hp",40000);
  set_skill("dodge",150);
  set_skill("unarmed",150);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) ); 
        set("chat_chance_combat",3);
        set("chat_msg_combat",({ 
      (: FG :),
      (: random_move() :), 
      (:command("follow "+this_player()->query("id")+""):), 
      (: flee :), 
}));  
  setup(); 
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*30) > tdex+tcon)
    {
      message_vision(HIY"\n\n$N"+HIW"嘴裡青光隱現！\n"
                    +HIG"巨大能量突然噴出！..\n"
                    +HIR"$n即刻淹沒在巨大能量裡！\n\n"+NOR,me,target);  
     target->receive_damage("hp",700+random(200), this_object());
      return 1; 
    }
}   

void flee()
{
     object me=this_player(),ob=this_object(); 
     if (ob->is_busy() ) return;
     //if(ob->query("hp") < ob->query("max_hp")/10)
     switch(random(6))
     {       case 0:
             message_vision(HIY"轉龍"+HIW"跳向旁邊的炎漿裡，不見了！？\n"+NOR,me);
             destruct(ob);
             break;
             case 1:
             message_vision(HIY"轉龍"+HIW"想跳向旁邊的炎漿裡，但是被"+me->query("name")+"擋了回來！\n"+NOR,me);
             me->start_busy(2); // 擋龍所以 busy 
             break;
      }
      return;
}   
void FG()
{
     object me=this_player(),a,b,c;
     if(this_object()->is_busy()) return;
     else{ message_vision(HIY"轉龍"HIR"大吼一聲！一團團的氣勁！漸漸凝聚！\n"NOR,me);
           a=new(__DIR__"red-ball");
           b=new(__DIR__"blue-ball");
           c=new(__DIR__"green-ball");
           a->move(environment(me));
           b->move(environment(me));
           c->move(environment(me));
           a->kill_object(me);
           b->kill_object(me);
           c->kill_object(me); 
         }
      return;
}/*
int S_ATTACK(string arg)
{
    object me=this_player(),ob=this_object(); 
    if(ob->is_busy() ) return;
    if(!me->query("class1")=="疾風門")  
    {
    switch(random(6))    {     case 0:
          message_vision(HIY"$N"+HIW"一個甩尾，正好打中了"+me->query("name")+"的$l！"+NOR,me);          me->receive_damage("hp",500,this_object());
          break;
          case 1:
          message_vision(HIY"$N"+HIW"奮力一抓！抓的"+me->query("name")+"是遍體鱗傷••\n"+NOR,me);
          me->receive_damage("hp",400,this_object());
          break;
          case 2:
          message_vision(HIY"$N"+HIW"向$n狂奔而去！撞的"+me->query("name")+"飛了十餘尺遠！\n"+NOR,me);
          me->receive_damage("hp",600,this_object());
          break;
    } 
    return 1; 
    }
} 
*/
varargs int receive_damage(string type, int damage, object who)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                        damage/=2;
                        message_vision("$N大吼一聲！瓦解了敵人的攻勢！\n" NOR,this_object());

                }
                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}

void die()
{
   object ob,eqp;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision", 
    HIR"\t【聖  炎  殿】"+HIG"地  "+HIY"轉龍  "+HIW"被"+ob->name(1)+"殺掉了。\n\n"+NOR,users());
        if( random(17) ) 
                eqp=new(__DIR__"obj/dragon-ring");
        else  if( random(3) )
                eqp=new(__DIR__"obj/dragon-sword");
        eqp->move(this_object());
        ::die();
        return;
}

