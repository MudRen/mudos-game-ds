#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name( "�q���s�ꤦ", ({ "dragon-tiger pill","pill" }));
        set("long",@LONG
�o�O�@�ɥѯ��u���~�s�ꨭ�W���o���ĤY�A�ǻ��㦳�D�`���_���ɦ�ĪG�C
LONG
        );
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("eat_msg","$N�]�U�@���j�p���Y���ĤY�A�t�I�S�C�b���V�̡C");
                set("eff_msg",HIG "�Aı�o�餺����G�����a�m�ˡA���G�S���Τ������A��C" NOR );
        }
        set("value", 5000);
        set("heal",([
                "hp": 3000,
        ]));
        setup();
}

