#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
        set_name(WHT"�ӥҮ�"NOR,({"Shoulder fist","fist"}) );
        set_weight(5000);
        set("long",@long
�@�ƩM���K�ӥҤ@�馨���������Z���A����Q�Υ��������q�[�j������⪺�ˮ`�C
long
        );
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",1500);
        set("unit","��");
        set("wield_msg","$N�ϫl�ϤF�Ϩ��l�A�ܰ_$n�C\n");
        set("material","iron");
        init_fist(30);
        set("weapon_prop/armor",10);
        }
        setup();

}

