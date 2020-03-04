#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void sword_check();
void create()
{
set_name("�������C",({"yin-yang longsword","sword","longsword"})); 
set("long","�o�O�@��ѿW�u�ѤH�ҥ��y�X�Ӫ��̨γǧ@�A���O�{�b�C���o��o\n"
           "�t�H�L���E\n");
set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("limit_str",40); 
        set("limit_int",40);
        set("limit_dex",60); 
        set("limit_level",47);
        set("value",10000);
        set("material","blacksteel");
        }
        init_sword(40);
        setup(); 
        call_out("sword_check", 0);
}

void sword_check()
{

        object me = environment(this_object()),
               ob = this_object();
        string sex;
        sex = me->query("gender");

        if( !this_object() || !me ) return;
        if( interactive(me)
         && me->query_temp("weapon") == this_object())
        { 
          if ( me->query_skill("force") > 90 && me->query("ap") > 1000 ){
             if ( sex == "�k��" ) {        
              if( !ob->query("male") ){
              message_vision(HIR"$N�N�������O��J�C���A$n"HIR"���C���B�X�H�H�������E\n"NOR,me,this_object());
              me->receive_damage("ap",1000);
              ob->set("male", 1);  
              ob->set("long","�o�O�@��ѿW�u�ѤH�ҥ��y�X�Ӫ��̨γǧ@�A�{�b�C����X�H�H\n"
                             "������\n");
              }
             } else {
              if( !ob->query("female") ){
              message_vision(HIC"$N�N�������O��J�C���A$n"HIC"���C���{�X�G�����C���E\n"NOR,me,this_object());
              me->receive_damage("ap",1000);
              ob->set("female", 1); 
              ob->set("long","�o�O�@��ѿW�u�ѤH�ҥ��y�X�Ӫ��̨γǧ@�A�{�b�C����X�G��\n"
                             "���C��\n");
              }
             }
          }
       }
 
        if ( ob->query("male") && !ob->query("female") ) {
             ob->set_name("��"HIR"��"NOR"���C",({"yin-yang longsword","sword","longsword"})); 
           }
        else if ( ob->query("female") && !ob->query("male") ) {
             ob->set_name(HIC"��"NOR"�����C",({"yin-yang longsword","sword","longsword"})); 
           } 
        else if ( ob->query("female") && ob->query("male") 
                  && !ob->query("power") && ob->query("equipped") != "wielded" ) {
             ob->set_name(HIC"��"HIR"��"NOR"���C",({"yin-yang longsword","sword","longsword"})); 
             ob->set("power", 1); 
             ob->set("long","�o�O�@��ѿW�u�ѤH�ҥ��y�X�Ӫ��̨γǧ@�A�C�b���a�観�۵�\n"
                            "�����H��A�H�𪺥~��o�S�]��F�@�h�x��A�J�⤧��A�O�H��\n"
                            "���@�_�C\n"); 
        set("wield_msg","$N�q�I���X�@��$n�A�u��$N���ǳ�¶�ۤ@�ѳ����թM����C\n");
        set("unwield_msg","$N��U�⤤��$n�A�N$n���J�I�᪺�C�T���C\n");
              set("weapon_prop/bio",-1); 
              set("weapon_prop/sou",-2); 
              set("weapon_prop/bar",random(3));
              set("weapon_prop/tec",random(3));
              set("weapon_prop/wit",1+random(2));
              set("weapon_prop/int",1+random(4)); 
              set("weapon_prop/hit",15);
              set("weapon_prop/damage",55);
          } 
        call_out("sword_check", 0);
} 

void attack(object me,object victim)
{
  object ob = this_object(),
         ppl = this_player();      

        int aa,aa1,power,mysk,myint,hp,mp,ap,time,times;
        hp = random(ppl->query("max_hp")*11/40);
        mp = random(ppl->query("max_mp")*11/60);  
        ap = random(ppl->query("max_ap")*11/50);        
        
        ::attack();
        if(!ob->query("power")) return;
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return; 
        
    switch ( random(30) ) {
      case 1:        
        message_vision(HIG"\n$N�⤤��$n"HIG"�o�X�@�ѷŷx���𮧡K"
                      +"\n�o�ѷŷx������$N�����b�c�����������ϤɡI\n\n"NOR,ppl,ob); 
        tell_object(ppl,HIC"�ͩR�I��(HP)�G"+HIY+"("+hp+")"+HIC+ 
                          "�@�]�k�I��(MP)�G"+HIY+"("+mp+")"+HIC+ 
                          "�@���l�I��(AP)�G"+HIY+"("+ap+")"+NOR+"\n");

        ppl->receive_heal("hp",hp);
        ppl->receive_heal("ap",ap);  
        ppl->receive_heal("mp",mp); 
      break;
      case 2..6:
        if(me->query_skill("star-sword") > 90
        && me->query("dex") >= 40
        && me->query("ap") > 100 ) 
        {
        message_vision("\n$N"HIW"�⤤��"+ob->query("name")+HIW"�X�@�}ģ�����ե��A���~���o�X�@�ѱj�P����������ĦV$n�I\n"NOR,me,victim);
        mysk = me->query_skill("sword");
        aa1=me->query("MKS")/20000;
        if (aa1 < 1) aa1=1;
        if (aa1 > 4) aa1=4;
        power= (mysk+myint)/2;
         
         for (aa=0;aa<aa1;aa++)
         { 
          me->add_temp("apply/damage",power);
          COMBAT_D->do_attack(me, victim, this_object(), 1+random(4));
          COMBAT_D->report_statue(victim); 
          me->add_temp("apply/damage", -power);  
         }
        me->receive_damage("ap",random(25)+15);
        }
 
        if(me->query("int") >= 50
        && me->query("mp") > 400 
        && me->query_spell("god-fire") > 91 ) {
        myint = me->query("int");
        mysk = me->query_spell("god-fire"); 
        
        times =  myint/33+mysk/33;        
        message_vision(HIY"\n$N�N�⤤$n"HIY"���Ť��@�ߡA�ٮɶ�"+chinese_number(times)+"�����y�q$N�⤤�g�g�ӥX�I�I\n"NOR,me,ob);
        for (time=0;time<times;time++)
         {
           SPELL_D("god-fire")->cast_fire(victim,me,mysk,myint);
           me->receive_damage("mp",20);
         }
        }
      break;
     } 
  return; 
}

