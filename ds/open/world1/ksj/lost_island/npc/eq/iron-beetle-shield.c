#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(CYN"�ΥҬ�"NOR,({"iron-beetle shield","shield"}));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("unit", "��");
        set("volume",3);
        set("long", @LONG
    ���δ߻s�����@���޵P�A�۷����Ӱ�T�A���ƪ����󦳧U��
���}�צ�ĤH�������C�C
LONG
        );
        set("value",2000);
        set("material","fur");
        }
        set("armor_prop/armor",15);
        set("armor_prop/block",10);
        set("armor_prop/dex",2);
        setup();
}
