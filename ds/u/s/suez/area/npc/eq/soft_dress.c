#include <armor.h>

inherit CLOTH;

void create()
{
set_name("��ù�u��",({"soft dress","dress"}) );

set_weight(275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","�o�O�@��륩����A�A�b���u�N�ݤf�έI��O�b�z�������h�C\n"
                "�S���h�l���Ϲ��A�o��Ϭ�W�����H��[�g�H�C���L�A���n��\n"
                "��A�n�����u�ܡv�n�ݤ~��C\n");
set("material", "silk");
set("unit", "��");
set("value",500);

//set("female_only");
set("armor_prop/armor", 1);
set("armor_prop/shield", 1);
        }
        setup();
}
