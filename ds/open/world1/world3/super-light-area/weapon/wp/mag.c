#include <ansi.h>; 
#include <weapon.h>
inherit GUN;
void create()
{
set_name(HIY"�̮�60"NOR,({"mag .60","mag"}));
set("long","��9��̤�j��_��,�o��b�۰ʤ�j�b���O�譱�����j�����ɡC\n[�̦h����30�o�l�u]\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",2000);
                set("rigidity",600);   
                set("material","iron");
        }

        set("wield_msg","$N�q���W�ǥX�@��$n, �ñN$n���O�I��Զ}�C\n");
        set("unwield_msg", "$N�N�⤤��$n�O�I����^, �é�^���W�C\n");
        set("bullet_type","mag");     
        set("max_load",30);           
        init_gun(15);   
        setup();
}

