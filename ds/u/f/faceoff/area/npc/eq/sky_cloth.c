#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(MAG"�����Ԧ�"NOR ,({ "sky cloth","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","�o�O�ǻ����W�j�ɥN�k�E�Ҭ諸��m, �ǻ���͢��۳o���A\n"
		   "����C�m���_�ɤѪŪ��}�}, �ڻ���W���|���쯫�O���O�@, \n"
		   "�����ޫ���, �o���@�ҵ��靈�A�e�ҥ��������_���m�O�C\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/shield",2);
                set("armor_prop/armor", 19);
        }
        setup();
}
