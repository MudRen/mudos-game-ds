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
set("limit_dex",20); 
set("limit_level",40);
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
init_sword(50+random(30));
setup();
}
void attack(object me,object victim)
{
  object ob = this_object();      
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(20)) return; // 1/20 �����v�S��
                message_vision("$N"HIG"�⤤��$n"HIG"�o�X�@�ѷŷx���𮧡E�E�E"
                      +"�o�ѷŷx������$N�����b�c�����������ϤɡI\n"NOR,me,ob);
        me->receive_heal("hp",me->query("max_hp")*11/40);
        me->receive_heal("ap",me->query("max_ap")*11/40); 
  return;
}

