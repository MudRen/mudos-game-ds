#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY "���\��"NOR,({ "golden-silk-cloth","cloth" }) );
        set("long",
"�H�����N�ɤ��s���_�Ӫ���A�A�q�`�O���F�����Q�ڦ���I���ӻs
�A�ӳo�@����\�窺�ɤ��Q����ӡA�Ϩ䤣�������@�몺���\��p��
�A�åB�ɤ��󴲵o�X�ż��A�������A�A�ݨӳo�ǥɤ����l���F�X�ʦ~
���H�����~���o�˪����R�C�C\n"
);
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/int", -1);
        }
        setup();
}

