#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(MAG"�����Բ�"NOR ,({ "sky hat","hat" }) );
        set("long","�o�O�ǻ����W�j�ɥN�k�E�ұa�����ݻs��, �����Ѥ��U�o�S��
�@�ӤH�i�HŲ�w�����s�y����, �ҥH�u�໡�O�W�ѶǤU�����ݤF....�C\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor",  9);
                set("armor_prop/shield",  20);
                set("value", 2300);
        }
        setup();
}