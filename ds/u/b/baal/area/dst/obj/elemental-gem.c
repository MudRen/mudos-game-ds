#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�����k�]"NOR,({ "element gem","gem" }));
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long",@LONG
�o�O�@�������_�����k�], ���O��A�N�����񲴷��Ӭݮ�, �i
�H�ݨ����ɦ��{�q�b�䤤����, �H�Τ��V���b��, ���̥O�A�P��
�_�Ǫ��O, �����~�����M���F�@�h��������, ��A�N�����⤤��
���G�i�H�P��j�۵M���������O�q���b�A�⤤��ģ...
LONG
);
                set("unit","��");
        }
        setup();
}


