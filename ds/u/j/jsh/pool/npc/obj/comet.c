#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�k�P�����E�}"NOR,({"comet_strick back-pou","pou"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
               "���D�Ѧa���ۡA���t�k�P�һs�A�b�T�w���ɶ��|�o�X���ݯ몺�O�q�A�]�i�ϥβֿn�_�Ӫ��O�q(back)�C\n");
             }
        set("value", 42000);
        set_weight(6000);     
  
        setup();
}
void init()
{
     add_action("do_back","back");
}
int do_back(string arg)
{
    object me,ob,victim;
    me=this_player(); 
    ob=this_object();
    if(!me->is_fighting())
    return notify_fail("�A�S���b�԰��I\n"); 
    victim = me->select_opponent();
    message_vision(HIW"$N"HIC"�������|�_"+ob->name(1)+"�äj�ۡG���t�O�q�I�I�k�P�E�}�I�I\n"NOR,me);
    me->start_busy(3);
    if(random(10) >5)
    {
    message_vision(HIR"�@�D���������~Ţ�n��"+victim->query_name(1)+"�A�P�@�ɶ��A�@�ѥ��j�������q"+victim->query_name(1)+"�����z�o�X�ӡI\n"NOR,me);
    COMBAT_D->do_attack(me,victim,this_object(),5);
    COMBAT_D->report_status(victim);
    victim->add_busy(8);
    victim->receive_damage("hp",500+random(500));
    victim->receive_damage("ap",400+random(400));
    victim->receive_damage("mp",300+random(300));
    } 
    else{
    message_vision(HIW""+victim->query_name(1)+"�{�L�F������Ţ�n�I�I\n"NOR,me); 
    me->add_busy(2);
    }    
    destruct(this_object());
    return 1;
}
void attack(object me, object victim) 
{    int damage,tk_one;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("force") > 80 && me->query_con() > 60 && random(10)<3 )
    {
      message_vision(HIW "\n�y��z���@�n�T�I"HIY"�k�P�����E�}"HIW"�����K�O�q�����z�o�I�I\n" NOR,me,victim);
      damage += me->query_skill("force")+me->query_con()+random(50);
      tk_one += victim->query_skill("parry")+victim->query_dex();
      tk_one = tk_one/3;
      if(damage-tk_one>0 && random(10)>5)
      {
        damage=damage+random((damage-tk_one));
        message_vision(HIR "�L��������A����a���U�@���K�ۡA�{�V"+victim->query_name(1)+"�A�u�������|�z�I\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
      else 
      message_vision(HIG "$N�V�Ǥ@���A�{�L�F�o�P�R���@���C\n"NOR,victim);
    }
    return;
}

