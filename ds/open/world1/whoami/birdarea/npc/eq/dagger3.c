#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit NEEDLE;

void create()
{
          set_name(MAG"�Q���F��"NOR,({"viper needle","needle"}) );
          set("long","�@�ڵ��⪺�w�A�Ϊ����O�@���D�A��A�`�N�ݮɡA�n���|�p���ͩR��
�w�w�C�ʡA�w�W�������������ݨ�@�h����C\n");
        set_weight(2300);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
              set("value",40000);
              set("limit_level",30);
              set("material", "blacksteel");
        }
        set("wield_msg","$N����F$n�A��W����������{�C\n");
         init_needle(40);
        set("soul_times",0);
        set("soul_levels",0);
          set("replica_ob", __DIR__"needle.c");
        set("weapon_prop/str", -4);
        set("weapon_prop/tec", 1);
        set("weapon_prop/int", 3);
        setup();        
}


void soul_lv(int lv)
{
 mixed level = ({"�ŵL�@��","���J�ι�","�W�~���S","�l���«C","�`���i��"
                 ,"�X���޵�","�n�p�y��","���ѷ��a",});
 int times,levels;
 times = this_object()->query("soul_times");
 levels = this_object()->query("soul_levels");
 times = times + lv;
 if (times >= (levels+1)*15 && levels < 15)
 {
  levels = levels +1;
  times = 0;
  write(MAG"�Q���F�ʬ�M�x�_�@�D�����E�E\n"NOR); 
    if(levels<=15) set("long","�@�⵵�⪺�w�A�Ϊ����O�@���D�A��A�`�N�ݮɡA�n���|�p����\n"+
                            "�R��w�w�C�ʡA�P�W�������������ݨ�@�h����C\n"+
                            query("name")+"���šG"+level[levels/2]+"\n");
  set("soul_levels",levels);
  this_object()->unequip();
  init_needle(40+levels*2);
  this_object()->wield();
  set("backstab_bonus",10+levels*3);
 }
 set("soul_times",times);
 return;
}
 
void attack(object me,object victim)
{ 
  int lv;
  int attack_times;
  object ob = this_object();      
        ::attack(); 
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;

       if (((!victim) || (victim->query("hp") < 0)))  //�䤣�������H(�i�ॴ��mob�bquery��hp<0�e���})
       {                                               //�άO����mob�æb���query��mob hp<0
       if(victim) lv=victim->query("level");
       else lv=1;
       message_vision("$N"HIC"�⤤��"NOR+MAG"�Q���F��"NOR+HIC"��M�ۤƦ��@�����D�A�N$n����z�l���C\n"NOR,me,victim);
       soul_lv(lv * 2);
       }

        if(random(5)) return; // 1/5 �����v�S��
        message_vision("$N"MAG"�⤤���Q���F�ʦp�D�@��V$n�֧�ƩۡI\n"NOR,me,victim);
        attack_times=me->query_dex()/30;
        switch( attack_times ) {
         case 0: 
          message_vision(HIY"\n�L�@$N�]���𤣨��ϱo�����L�k�s��U�h�E�E\n"NOR,me,victim);
          me->start_busy(1);
          break;       
         case 1:
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);   
          break;
         case 2:
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);  
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);   
          break;
         default:
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);  
          COMBAT_D->do_attack(me, victim, this_object(), 4);
          COMBAT_D->report_statue(victim);    
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);   
          break;        
        }
        return; 
} 

