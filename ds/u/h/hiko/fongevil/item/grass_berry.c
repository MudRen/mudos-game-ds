//�\��H��A�g..next area�ݭn��
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�G�ï�ؤl", ({ "berry" }));
        set("long","�G�ï󪺺ؤl�A�ݨӷ��A�X�����ƪ����ơC\n");
        set_weight(450);

        if( clonep() ) 
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value", 500 );
        }
        setup();
}

