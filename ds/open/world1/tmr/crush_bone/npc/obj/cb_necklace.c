#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("�H���붵��", ({ "crush bone necklace","necklace"}) );
        set_weight(2000);

        if( !clonep() ) {
                set("unit", "��");
                  set("value", 600);
                set("long",@long
�o�O�@���ѸH���뤤�b�~�H���y�Ӧ�������A�y���㦳�@�ح�l����
���O�q�A���]���ѵ������̤��������m��O�C
long
        );
                set("armor_prop/armo", 5);
		} else
		   set_default_object(__FILE__);
        setup();
}

