#include <weapon.h> 
#include <ansi.h>
inherit F_UNIQUE;
inherit FORK;
void create()
{
        set_name("���j"HIY"�g��"NOR,({"sun longpike","longpike","pike"}) );  
        set("long","�������H���Z���A���F�ʤ�A�@��H�s���ۨ��������x���A��O��\n"
                   "�˳Ʀ��Z���F���]���]���p�������ˤO�~�|�o����H�E\n");
          set_weight(23000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("replica_ob", __DIR__"steel_pike.c");
        set("unit","��");
        set("value",8600);
        set("volume",4);
        set("material","iron");
        set("limit_str",95);
        set("limit_lv",45); 
        set("weapon_prop/str",4);
        set("weapon_prop/con",2); 
        set("weapon_prop/dex",-4);
        set("weapon_prop/bar",2); 
        set("weapon_prop/wit",-2);
        set("weapon_prop/dodge", -25); 
        set("weapon_prop/hit", -50);
        init_fork(89);
        }
        setup();
}

