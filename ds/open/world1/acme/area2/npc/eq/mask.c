#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name("�ߤ�����" ,({ "ghost mask","mask" }) );
        set("long","�o�ӭ���O�խߦa�����ߤ��Ҭ����ɤ����y���z�����A\n"
                   "�ݰ_�ӤQ���u��i�ơA������������@�ΡC\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","fur");
        set("unit","�i");
        set("value",100);
        }
	set("armor_prop/int",1);
	set("armor_prop/armor",3);
        setup();
}
