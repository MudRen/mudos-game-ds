#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me);

int query_pan();

void create()
{
        set_name(HIG"��������" NOR ,({"pan's eye","eye", "_PAN_EYE_"}) );
        set_weight(10);
        set("long",@LONG
�o�O�@�ɳ��ժ��۲��A���O�J�Ӥ@�ݫo�����O�H���������A�Ϧ�
������O�ϲ��C�o�ɥ۲��W�������t��������A�ݼˤl�w�g�s�b
�W�L�X�ʦ~�F�A�����D�O�q��B���۹��W�����U�Ӫ��C
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value", 10);
        }
        setup();
}