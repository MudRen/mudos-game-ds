#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW""BLK"�۹�"NOR, ({ "statue"}));
        set("long", 
"�o�O�@�L�J�u���W���۹��A�q���V�ª��C��ݨӡA���ӬO�ݩ�`\n"
"�s�q�ۡC�۹��������ݰ_�Ӧ��Q�H���ʪ�����....\n");
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 1);
                set("no_get", 1);
                set("no_sac", 1);
        }
        setup();
}

