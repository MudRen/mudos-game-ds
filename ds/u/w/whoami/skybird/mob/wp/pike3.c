#include <weapon.h> 
#include <ansi.h>
inherit FORK;
void create()
{
        set_name(HIB"���s"NOR"���u",({"dragonfly halbert","halbert"}) );  
        set("long","�j�������A���A�ӤH�A�������ۯ��ˡA�j�y�B�W�Q�����A����S�ΡA\n"
                   "����j�`�ɺݳBű�ۨ�ӥj�r�R���s�E\n");
        set_weight(11000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",7300);
        set("volume",4);
        set("material","iron");
        set("limit_str",55); 
        set("limit_dex",20);
        set("limit_level",30); 
        set("weapon_prop/str",2);
        set("weapon_prop/con",1);
        set("weapon_prop/int",-1);
        set("weapon_prop/dex",-1);
        set("weapon_prop/dodge", -5); 
        set("weapon_prop/hit", -5);
        init_fork(57, TWO_HANDED);
        }
        setup();
}

