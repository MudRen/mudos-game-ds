#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name("����" ,({ "face-dermo" , "dermo" }) );
        set("long","�o�O�ΨӫO�i�ֽ��������A���j�P���H�ʡC\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "peel");
        set("unit", "��" );
                set("value",10);
        }
        set("armor_prop/armor", 1);
        set("armor_prop/id",({"dermo people"}));
        set("armor_prop/name",({"�y���������ǤH"}));
        set("armor_prop/short",({"�y���������ǤH"}));
set("armor_prop/long",({"�@���y���������H�A�A�߸̤��T�h�áA�O���O�@�ӯ��g�f�C\n"}));
        setup();
} 
