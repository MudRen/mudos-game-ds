#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit MASK;

void create()
{
        set_name(HIW"�ߤ�����"NOR,({ "ghost mask","mask" }) );
        set("long","�o�ӭ���O�խߦa�����ߤ��Ҭ����ɤ����y���z�����A\n"
                   "�ݰ_�ӤQ���u��i�ơA������������@�ΡC\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","fur");
        set("unit","�i");
        set("value",100);
        set("limit_lv",25);
        set("limit_int",33);
        set("replica_ob",__DIR__"mask");
        }
        set("armor_prop/int",2);
        set("armor_prop/armor",2);
        set("armor_prop/wit",1);
        set("armor_prop/bio",-1);
        setup();
}
