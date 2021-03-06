#include <ansi.h>
inherit NPC;
void combat_ai(); 
int special_attack(); 
void do_healmpap(object me);
void heal();

void create()
{
        set_name("正一法師", ({"chan-ei taoist","taoist"}));
        set("long",@LONG

LONG
);
        set("title", HIY"龍虎山"NOR );
        set("age", 120);
        set("level", 60);
        set("exp", 100000);
 set("max_hp",14000+random(3000)); 
 set("max_ap",8000+random(5000)); 
 set("Merits/bar",1+random(6));  
 set("Merits/wit",5+random(6));  
 set("Merits/tec",3+random(5));  
 set_temp("apply/str",15+random(30));  
 set_temp("apply/dex",15+random(30));  
 set_temp("apply/armor",35+random(30)); 
 set_skill("force",100); 
 set_skill("dodge",120); 
 set_skill("unarmed",120); 
set_skill("hammer",120);  
 set("chat_chance_combat",300);
 set("chat_msg_combat",({
                         (: combat_ai :),
        (: special_attack() :), 
 })); 
 set_temp("pill",6);
 setup();
 set_living_name("Wulianq_Bonze"); 

} 

void combat_ai()
{
        int i,x;
        object *target,npc;

        target = all_inventory(environment(this_object()));
        x = sizeof(target);

        /* 武器被打掉，則裝回去 */
       if( !this_object()->query_temp("weapon") ) 
                command("wield hammer"); 

        /* 受傷時會自我醫療  */
        if( this_object()->query("hp") < this_object()->query("max_hp")/3 ) 
        this_object()->add_busy(-2);
        heal();


        return;
}



int special_attack()
{
  object me = this_object(); 
  if(!me) return 1;
  if(!random(5))
{
    me->start_busy(1);
//    target->add_busy(2);
    message_vision(HIW"\n$N只用持著拂塵的左手，在身前虛空畫圓，單手結道教密印，五指屈伸，指尖隱隱發出金光，片刻間已在身前化出一面太極，金光輝煌！\n\n"NOR,me);
    call_out("do_healmpap",2,me);
//    return 1;
}
  return 0; 
}

void do_healmpap(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;
message_vision(HIM"$n的身體為之一顫，行動開始隨著太極轉動遲緩下來！\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
{
    if(inv[i] == me) continue;
    if(living(inv[i]) )
{
        if( inv[i]->is_corpse() ) continue;
      if( !inv[i]->is_fighting(this_object()) ) continue;
      damage = random(50)+250;
message_vision(HIM"$n的身體為之一顫，行動開始隨著太極轉動遲緩下來！\n\n"NOR,me);
      inv[i]->receive_damage("ap", damage, me);
      inv[i]->receive_damage("mp", damage, me);
      COMBAT_D->report_status(inv[i]);
}
    else
{
message_vision(HIM"$n身體一顫，行動開始遲緩下來！\n\n"NOR,me);
      destruct(inv[i]);
}
}
  me->start_busy(2);
  return;
}

void heal()
{
    object me=this_object(); 
    if( !me->query_temp("pill") ) return;
    if( me->query("hp") > me->query("max_hp")/3 ) return;

    message_vision("$N從懷中掏出一顆"HIY"金色藥丸"NOR"，隨即吞了下去•\n", me);              
    me->receive_heal("hp",me->query("max_hp"));
    me->receive_heal("mp",me->query("max_mp"));
    me->receive_heal("ap",me->query("max_ap"));
    me->add_temp("pill",-1);
    return;
}
varargs int receive_damage(string type, int damage, object who)
{
        int val,time;

                if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
                if(random(10)<4)
                {
                   message_vision(HIM"$N身上冒出淡淡的紫色光芒，$n身體一顫，$n似乎氣力疲弱了一點！\n"NOR,this_object(),who);
                   for (time=0;time<1+random(2);time++) 
                   { 
                   this_object()->add_busy(-2);
                   COMBAT_D->do_attack(this_object(),who,this_object()->query_temp("weapon"),4);
                   COMBAT_D->report_statue(who); 
                   }
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
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
        ob->add("popularity",5); 
     call_out("wakeevil",5);
/*
        message("world:world1:vision",
        HIY"\n龍虎山 "HIC"正一法師 "HIW"仰天長嘯道﹕"HIW"「"HIR"道將死，釋將亡，妖魔稱王，天下淪喪﹗﹗"HIW"」\n\n"NOR
        HIM"\t【靈山警鍾】\n"NOR
        CYN"\n\t\t妖魔錄持有者正一法師死於邪徒"+ob->query("name")+"之手！！\n"NOR
        ,users() );
*/
        tell_object(ob,HIW"\n(因為你殺死了正一法師，所以得到了 5 點聲望。)\n"NOR); 
        ::die();
        return;
}

void wakeevil()
{
        message("world:world1:vision",
CYN"\n你耳邊傳來模糊的歌聲。。。\n"NOR
WHT"\t\n福兮，禍兮，煉獄人間，靈兮，欲兮，何以為魔？。。。。。。\n"NOR
        ,users() );
        return;

}
