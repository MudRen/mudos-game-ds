#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIW "�ջȾԥ�" NOR,({ "silver armor","armor" }) );
        set("long",
"�ջȾԥҬ۶Ǭ������@�L�k���������@��ԥҡA�`��ۦ���ѥ[���P\n"
"�ԧСC���M�����»ȥ��y�A�o�w�Q�L�ƼĤH���A��V�۱a���@���H����C\n"
);
        set_weight(22500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "silver");
        set("unit", "��" );
	}
        set("limit_con",30);
        set("limit_lv",25);
        set("value",4600);
        set("armor_prop/armor", 30);
        set("armor_prop/dex", -4);
        set("armor_prop/con",  2);
        setup();
}

