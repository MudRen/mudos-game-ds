#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIR "���ĭ���" NOR ,({ "zhu-rong mask","mask" }) );
        set("long",@long
�o�O�@�Ө�W���Ĥ��������s����A�ݮݦp�ͪ����į��ϩ��b����W
�C�ʡC���ĭ�����G�ǨӤ@�}������Pı�A���A���۸T�a�y�U���ӡC
long
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","gold");
                set("unit","�i");
                 set("value",2500);
	        set("limit_lv",30);
                set("limit_int",40);
        }
        set("armor_prop/int",2);
        set("armor_prop/armor",8);
          set("armor_prop/shield",20);
        set("armor_prop/wit",1);
        set("armor_prop/bio",-1);
        set("armor_prop/bar",-1);
        setup();
}

