#include <armor.h>

inherit FINGER;

void create()
{
        set_name("�S�ϫ���", ({ "envoy ring", "ring" }) );
        set_weight(500);

        if( !clonep() ) {
                set("unit", "�T");
                  set("value", 3000);
                set("long",@LONG
�o�O�@�T�θH�����K�q�����ʻɥ��y�Ӧ��������A�W���観����
�W���G���Ÿ��C
LONG
                );
                set("armor_prop/int",1);
        } else
		   set_default_object(__FILE__);


        setup();
}

