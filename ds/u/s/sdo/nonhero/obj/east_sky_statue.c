#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name(HIC"�F�����ѤѤ��J��"NOR,({"east sky statue","statue" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long",@LONG
���Ѭ��@�@�|�Ѥ����@�A�M�u�@�F�ӯ��w�a��A���W�����Y��\�A
Ķ�@����A�Φw���C�`��Ѯc�A�O�����s���ĥ|�h�A�b�F�ӯ��w����
��ئ�A�����F�C�������D�C�H����@����g�A���O�H���x�o�wí�A
�G�W����ѡC���C�զ�L��A�����\�]�Ӽu�A�����Z�ҤѦ�C����
���}������B�c�@�B�@����g�A�������w���L�W���ѨӡA�Y�b���C
�b�Ѧ�b�g�«����A�q�u�@�F����¾�A�D�q���a���d�C
LONG
                );
                set("no_get",1);
                set("no_drop",1);
                set("value", 100000);
                set("unit","�y");
        }
        setup();
}