#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name(HIC"�_��h�D�ѤѤ��J��"NOR,({"north sky statue","statue" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long",@LONG
�ݥ|���Ѥ��@�A�������Ѥ��~�ڡA�H���@���@���G�A�S���@�@�̡A��
�ѧO�W�i�F���A��W���i��ù�i�ԡAĶ�@�M���B�����A�κغت����C
�]��`�@�p�ӹD���ûD�k�A�G�W���u�h�D�v�A���ּw���W�A�D��|
��C���@�_���f�w�A�`�����s�ĥ|�h���_����c�A���]�e��ù�b��
�����D�C�S���ñK�ҭz�A�]�_�Ѥ��W�u�n�q�¡v�A�D����򤧫n���_
�ͦ�ҤƲ{�C�]�_�Ѥ���������A�@���G�u�A�Y�������_�a�A�����
�����ҡA�ؽѺج��_�\���A�k���_�l�A�H��R�_���u�æC�v�A�H����
�p�N�����A�A�����a�շ�l�W�A���W��g�p�Q�U���餧���~�A�䳡
�ݬ��K���]���H����_�l���իB�����B�A��Ѧ�b�g�«����A�q�_
���u�@��¾�A�D�W�q�k���C
LONG
                );
                set("no_get",1);
                set("no_drop",1);
                set("value", 100000);
                set("unit","�y");
        }
        setup();
}
