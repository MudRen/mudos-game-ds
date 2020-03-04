#include <ansi.h>
inherit NPC;
void combat_ai(); 
int special_attack(); 
void do_healmpap(object me);
void heal();

void create()
{
        set_name("���@�k�v", ({"chan-ei taoist","taoist"}));
        set("long",@LONG

LONG
);
        set("title", HIY"�s��s"NOR );
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

        /* �Z���Q�����A�h�˦^�h */
       if( !this_object()->query_temp("weapon") ) 
                command("wield hammer"); 

        /* ���ˮɷ|�ۧ�����  */
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
    message_vision(HIW"\n$N�u�Ϋ��۩عЪ�����A�b���e��ŵe��A��⵲�D�бK�L�A�����}���A���y�����o�X�����A���趡�w�b���e�ƥX�@���ӷ��A�������סI\n\n"NOR,me);
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
message_vision(HIM"$n�����鬰���@Ÿ�A��ʶ}�l�H�ۤӷ���ʿ�w�U�ӡI\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
{
    if(inv[i] == me) continue;
    if(living(inv[i]) )
{
        if( inv[i]->is_corpse() ) continue;
      if( !inv[i]->is_fighting(this_object()) ) continue;
      damage = random(50)+250;
message_vision(HIM"$n�����鬰���@Ÿ�A��ʶ}�l�H�ۤӷ���ʿ�w�U�ӡI\n\n"NOR,me);
      inv[i]->receive_damage("ap", damage, me);
      inv[i]->receive_damage("mp", damage, me);
      COMBAT_D->report_status(inv[i]);
}
    else
{
message_vision(HIM"$n����@Ÿ�A��ʶ}�l��w�U�ӡI\n\n"NOR,me);
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

    message_vision("$N�q�h���ǥX�@��"HIY"�����ĤY"NOR"�A�H�Y�]�F�U�h�E\n", me);              
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

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
                if(random(10)<4)
                {
                   message_vision(HIM"$N���W�_�X�H�H��������~�A$n����@Ÿ�A$n���G��O�h�z�F�@�I�I\n"NOR,this_object(),who);
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
        HIY"\n�s��s "HIC"���@�k�v "HIW"���Ѫ��S�D�R"HIW"�u"HIR"�D�N���A���N�`�A���]�٤��A�ѤU�_��T�T"HIW"�v\n\n"NOR
        HIM"\t�i�F�sĵ��j\n"NOR
        CYN"\n\t\t���]�������̥��@�k�v���󨸮{"+ob->query("name")+"����I�I\n"NOR
        ,users() );
*/
        tell_object(ob,HIW"\n(�]���A�����F���@�k�v�A�ҥH�o��F 5 �I�n��C)\n"NOR); 
        ::die();
        return;
}

void wakeevil()
{
        message("world:world1:vision",
CYN"\n�A����ǨӼҽk���q�n�C�C�C\n"NOR
WHT"\t\n�֤��A�פ��A�Һ��H���A�F���A�����A��H���]�H�C�C�C�C�C�C\n"NOR
        ,users() );
        return;

}
