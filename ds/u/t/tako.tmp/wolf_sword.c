#include <ansi.h>
#include <weapon.h> 
inherit F_UNIQUE;
inherit SWORD;

void create() 
{
        set_name(YEL"�T���C"NOR,({"wolf-tooth sword","sword"}));
        set_weight(10000); 
                if( clonep() )
                set_default_object(__FILE__); 
 else { 
                set("long",
"�ѼƦʰ����T�������s����,�ߤW�ٷ|����ť�쳥�T�H�����n��\n" 
" ,���C�O�ѦWű�C�v,�F�C����ű�y��,�F��G�H,���]�O�ʰ��T\n"
"�һs,�F���ର���,�O���ɪZ���ƦW�Ƥ@�ƤG��\n"
);
        set("limit_dex",32); 
        set("limit_skill",70);
        set("unit", "��");        
        set("value",1000);
        set("volume",4);        
        set("wield_msg",MAG"$N�q�y�ک�X�@��$n,����$N�P�򪺴��X�L�񪺷ٮ�C\n"NOR);  
        set("unwield_msg",MAG"$N��U�⤤��$n,$N���`�f��,��ٮ�l�i�餺�C\n"NOR);
        set("material","steel");       
        set("weapon_prop/dex",-2); 
        set("weapon_prop/con",2);  
        set("weapn_prop/str",1);
        set("weapon_prop/int",-3);   
        set("weapon_prop/bar",1);
        set("weapon_prop/sou",-3);  
        set("replica_ob", "wolf sword2");     
        init_sword(65); 
           setup();
}    
}
int attack(object target)
{
 object me;
 me=this_player();
 if( random(8) < 6 )
 {
     message_vision("\n"
     +HIC"�@�}�H���n�q�T���C�ǤF�}��,�T���C���X�@�w�婹$n�ĥh�I\n"NOR
     +HIC"���M�ܦ��@���c�T,��$n���W�������r�F�U�h�I \n"NOR     +HIR"�y���|�ӻG�}\n\n"NOR,me,target);
 target->receive_damage("hp", 50+random(100));
 me->receive_damage("mp",40);
 me->add_busy(1);
 return 1;
}
else
{
     message_vision("\n"
     +HIR"�@�}�H���n�q�T���C�ǤF�}��,�T���C���X�@�w�婹$n�ĥh�I\n"NOR
     +HIR"���M�ܦ��@���c�T,��$n���W�������r�F�U�h�I\n"NOR
     +HIW"���O$n�b�d�v�@�v����,�V�W���}�F!\n\n"NOR,me,target);
     me->receive_damage("ap",10);
     return 1;
        }
}



