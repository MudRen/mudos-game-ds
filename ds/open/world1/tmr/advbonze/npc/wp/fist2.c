#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(HBK "���ʵL�ؤ�" NOR,({"bu-down wu-shou fist","fist"}) );
        set("long",@long
�@���Kű����K���l�A�W�Y�躡�F�ær��L�A�A���b��W���ة_����
�P���A���@�U���ШƦ��G�ݪ�����}�F�C
long
        );
         set_weight(2000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("volume",2);
                set("material","iron");
                set("value",12000);
                set("limit_level",30);
                set("limit_str",50);
        }
        set("weapon_prop/hit",10);
        set("weapon_prop/bar",1);
        set("weapon_prop/sou",-1);
        set("weapon_prop/con",2);
        init_fist(50);

        setup();
}

