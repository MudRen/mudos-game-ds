#include <ansi.h>
inherit ITEM;

string getLong()
{
        return sprintf("�j�h�ݭ���(dashi pudu xiang) [���� %d ��]",query("time") );
}

void create()
{
        set_name(HIY "�j�h�ݭ���" NOR,({"dashi pudu xiang", "xiang", "_GHOST_XIANG_"}) );
        set("long",@LONG
�۶��¾�C��A�Ҧ��b���@���`�F�A���k�u�j�h�ݡv�޲z�C�o�쯫�骺�ӥѦ��G�G
�@�O͢�O�[���j�h���ƨ��A�G�١u�j�h�ݡv�C�G�O͢�쬰�Ѱ�������A�]���[��
�j�h�ФƦӬԨ̨���U�A�q���Q�٧@�u�j�h�ݡv�A�����@����������ƶ��������C
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
        }
        set("value", 100);
        set("time", 1000 + random(1000) );
    
        setup();
        set("long", query("long") + getLong() );
}

