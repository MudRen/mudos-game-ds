#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(HIY"���l�j"NOR,({"light gun","gun"}) );
set("long","�@��W�����y���l�V�m���z���W�ŪZ���I\n");
set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1200);
                set("rigidity",800);    
                set("material","iron");
 set("limit_lv",15);
                                set("limit_con",5);
                set("limit_int",15);
                set("limit_str",15);
        }

        set("wield_msg","$N���_�@�����n���F�X�y�A���N�ܦ��F�@��$n�I\n");
        set("unwield_msg", "$N��$n�g�F�X�w���A$n�N�K�^�@�����n�C\n");
        set("bullet_type","light_clip");
        set("max_load",25);             //�̤j�˶�q
       init_gun(25);
        setup();
}
