#include <ansi.h>  
#include <armor.h>
inherit SHIELD; 
void create()
{
        set_name(HIW"���褧��"NOR,({ "water-mirror shield","shield" }) );
        set("long","�o�O�Υդ����Ӳӿi�����p�ޡA�����ƦӰ{�G�A�̭��h�躡�᯾ \n"                   "����]�k�������������Ϊ���ܤO�C\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","gold");
                set("unit", "��" );
                set("no_sell",1); 
                set("value",30000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",45);
        }
        setup(); 
        call_out("do_back", 100);
} 
void do_back(string arg)
{
     object me,victim,ob;
     me = this_player(); 
     ob = this_object();
     if(!me->is_fighting() ) 
     write(HIW""+ob->name(1)+"�L�L���ʤF�@�U�A�o�X�L�L���ե��E�E�E\n"NOR);
     victim = me->select_opponent();
     message_vision(HIW""+ob->query_name(1)+""+HIB"�o�ʤF���t�O�q�w"+HIG"�y�k�P�E�����z�I\n"+NOR,me);
     me->start_busy(2);
     if(random(10) >5 )
     {
     message_vision("�@�D"HIW"�ե�"NOR"��"HIC""+victim->query_name(1)+""NOR"Ţ�n��A����"HIR"���}�I�I\n"NOR,me);
     COMBAT_D->do_attack(me, victim, this_object(), 5);
     COMBAT_D->report_status(victim);
     victim->start_busy(5);
     victim->receive_damage("hp",200+random(33));
     }
     else
     {
     message_vision(""+victim->query_name(1)+"�V�Ǥ@�{�A���}�F�P�R���ե��E�E\n",me);
     me->add_busy(2);
     }
     return 1;
}
