#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name(HIC"���s�ؤѤѤ��J��"NOR,({"west sky statue","statue" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long",@LONG
�s�ؤѤ���W���s�өޤe�AĶ�@���y�B�D�n���B�c���B�s�ؤ��಴��
�ⵥ�C���笰�@�@�|�Ѥ����@�A�M�u�@���A�Y��������P�w�A�`��
�����s���ĥ|�h���ջ�ئ�A���s�ڡB���������D�C���Ѥ��H�غ�����
���Y�ѮڡA�䥻�}���g�@�o�H�A�Ϥ��J�쨯�W��A��_�D�ߡC�s�ؤ�
������A�@���G�u�A�ض�ӥ~�Y�A�Y���s���A�����Z�ҡA�k�⮻�s�A
���⦫��A��Ѧ�b�g�«����A�u�@�����¾�A�D�h�R�C�]�䬰����
���ҤơA������s���A�G�k�⮻�s�A���իB���C
LONG
                );
                set("no_get",1);
                set("no_drop",1);
                set("value", 100000);
                set("unit","�y");
        }
        setup();
}