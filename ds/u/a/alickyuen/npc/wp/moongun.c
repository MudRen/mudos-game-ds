#include <weapon.h>
#include <ansi.h>
inherit GUN;
inherit F_UNIQUE;

void create()
{
set_name(HIY"��v����"NOR,({"moonshade gun","gun"}));
set("long","�o�O�@��g���Z��, ť���O�@�ʦh�~�e�i��v���j�үd�U���Z��,�O�̭�l����C\n");
set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",2000);
                set("rigidity",800);    
                set("material","iron");
                set("no_sell",1);
                set("no_drop",1);
                set("no_sac",1);
//
// ����i�H�O   limit_lv        limit_str 
//              limit_dex       limit_con 
//              limit_int       limit_skill
//
   set("limit_lv",15);
                                set("limit_con",25);
                set("limit_int",25);
                set("limit_str",25);
        }

        set("wield_msg","$N�q��U�̮��X�@��$n�C\n");
        set("unwield_msg", "$N�N��W��$n��^��U�̡C\n");


//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit     �R���v
//  weapon_prop/parry   �۬[�v
//
        set("bullet_type","moon_clip"); //�i�Τl�u����
        set("max_load",25);             //�̤j�˶�q
        init_gun(14);   // �׷i�ˮ`�O=set("weapon_prop/damage", 14);
        setup();
}

