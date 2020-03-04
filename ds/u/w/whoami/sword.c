#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name(HIC"��"HIR"��"NOR"�C",({"negative positive sword","sword"})); 
set("long","�o�O�@��ѿW�u�ѤH�ҥ��y�X�Ӫ��̨γǧ@�A�C�b���a�観�۵�\n"
           "�����H��A�H�𪺥~��o�S�]��F�@�h�x��A�J�⤧��A�O�H��\n"
           "���@�_�C\n");
set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("limit_str",45); 
        set("limit_int",30);
        set("limit_dex",40); 
        set("limit_level",45);
        set("value",10000);
        set("material","blacksteel");
        }
        set("wield_msg","$N�q�I���X�@��$n�A�u��$N���ǳ�¶�ۤ@�ѳ����թM����C\n");
        set("unwield_msg","$N��U�⤤��$n�A�N$n���J�I�᪺�C�T���C\n");
        set("weapon_prop/sou",-2); 
        set("weapon_prop/bar",random(2));
        set("weapon_prop/tec",random(2));
        set("weapon_prop/wit",1);
        set("weapon_prop/int",2); 
        set("weapon_prop/hit",20);
        init_sword(40+random(30));
        setup();
}
void attack(object me,object victim)
{
  object ob = this_object(),
         ppl = this_player();      
        int aa,aa1,power,mysk,myint,hp,mp,ap;
        hp = random(ppl->query("max_hp")*11/40);
        mp = random(ppl->query("max_mp")*11/60);  
        ap = random(ppl->query("max_ap")*11/50);        
        
        ::attack();
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
        if(me->query("class1") != "�e����" && me->query("class2") != "�e����") return;
message_vision("\n$N"HIW"�⤤��"+ob->query("name")+HIW"�X�@�}ģ�����ե��A���~���o�X�@�ѱj�P����������ĦV$n�I\n"NOR,me,victim);
        myint = me->query("int");
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
      break;
     } 
  return; 
}

