#include <weapon.h> 
#include <ansi.h>
inherit FORK;
void create()
{
        set_name("�C���u��",({"steel pike","pike"}) ); 
        set("long","�������H���Z���A���ת��סB���q�ҫꥩ���y���४�����Z���E\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",8600);
        set("volume",4);
        set("material","iron");
        set("limit_str",65);
        set("limit_lv",35); 
        set("weapon_prop/str",2);
        set("weapon_prop/dex",1);
        init_fork(48, SECONDARY);
        }
        setup();
}


