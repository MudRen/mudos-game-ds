#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
        set_name(HIY "����@�P��" NOR ,({ "sun-moon gloves","gloves" }) );
        set("long",@LONG
�o�O�@���y���D�`�I�����䪺�@��A�o���@��W¸���@�T�u�����P�v
�����u�ϡA¸�u����A����o�T���Hø�s���ϵo����ɵ��ɬ��B�g���[��
���ҬɡA�u�i�׬O���ܤѤu�]�����L�C
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",2500);
        }
        set("armor_prop/armor",8);
        set("armor_prop/dex",1);
        setup();
}

