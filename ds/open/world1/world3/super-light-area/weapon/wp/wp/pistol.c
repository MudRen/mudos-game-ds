#include <ansi.h>; 
#include <weapon.h>
inherit GUN;
void create()
{
set_name(HIW"9��̤�j"NOR,({".9MM pistol","pistol"}));
set("long","�ݩ�b�۰ʫ���j, ���A�X�P�j�q�ĤH��ԮɨϥΡC
[�̦h����50�o�l�u]\n");
 set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1500);
                set("rigidity",700);   
                set("material","iron");
        }

        set("wield_msg","$N�q���W�ǥX�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
        set("unwield_msg", "$N�N�⤤��$n�O�I�˸m����, �é�^���W�C\n");
        set("bullet_type","9mm");     
        set("max_load",50);           
        init_gun(12);   
        setup();
}

