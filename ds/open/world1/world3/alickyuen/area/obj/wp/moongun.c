#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
        set_name(HIY"��v����"NOR,({"moonshade gun","gun"}));
        set("long","�o�O�@��g���Z��, ť���O�@�ʦh�~�e�i��v���j�үd�U���Z��,�O�̭�l����C\n");
          set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",2000);
                set("rigidity",800);    
                set("material","iron");
                set("limit_lv",15);
                set("limit_con",25);
                set("limit_int",25);
                set("limit_str",25);
        }

        set("wield_msg","$N�q��U�̮��X�@��$n�C\n");
        set("unwield_msg", "$N�N��W��$n��^��U�̡C\n");
        set("bullet_type","moon_clip"); //�i�Τl�u����
        set("max_load",25);             //�̤j�˶�q
        init_gun(20);   // �׷i�ˮ`�O=set("weapon_prop/damage", 14);
        setup();
}

