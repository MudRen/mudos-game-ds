#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name(HIC"�n��W���ѤѤ��J��"NOR,({"south sky statue","statue" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long",@LONG
�W���Ѥ��笰�@�@�|�Ѥ����@�A��W�s�ӰǤe�A�D�u�@�n¤���w�A�`
��Ѯc�A�������s�ĥ|�h���n�[��ئ�A�O���n�����y�]��������h��
�j���������D�C�䥻�}���W���ۥL���¼w�A�B���U����ͤ��w���A�G
�Ѧ��ӱo�W�C���L���C�C�Ŧ�A����_�C�A�Y�����~�~�a�A���Z�Ҥ�
��A��L��ۡC�b�Ѧ�b�g�«����A�q�n���u�@��¾�A�D����C
LONG
                );
                set("no_get",1);
                set("no_drop",1);
                set("value", 100000);
                set("unit","�y");
        }
        setup();
}