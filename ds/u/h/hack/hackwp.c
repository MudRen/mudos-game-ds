#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(RED"�b�ȯ��P"NOR,({"hack dagger","dagger"}));
set("long" ,@LONG
�o�O�@�ڪ����|�T���@���p�P���A�W����۳\�h�����W����r�A�ǻ��o���P���O�c�F�b�Ȫ��H���Z���A���o�@�ѯ������O�q�C
LONG
        );

     
   set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material","pem");
                set("no_sac",0);
        }
        set("value",2380);

        set("volume",1);
        
        set("monster_weapon_prop/bio",1);
        set("monster_weapon_prop/sou",-1);
        set("monster_weapon_prop/dodge",7);
        set("monster_weapon_prop/hit",12);
        set("monster_weapon_prop/damage",293);
        
        set("weapon_prop/bio",1);
        set("weapon_prop/sou",-1);
        set("weapon_prop/dodge",7);
        set("weapon_prop/hit",32);
        set("backstab_bonus",99);
        
        set("wield_msg",HIY"$N�N$n"HIY"���F�X�ӡA��$N�����R���F�q�y�C\n"NOR);
        set("unwield_msg", "$N�N�⤤��$n��U�A�q�y�]�H��$n�����F�C\n");
        
        init_dagger(293);
        setup(); 
   
}        

 


