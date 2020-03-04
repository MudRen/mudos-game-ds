#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("���ֻI��",({"dog plaster","plaster"}) );
        set("long",@long
�@�i�����O�q����ʪ����W�ޤU���֡A�W�Y�p�p�a��F�@�h�I�ġA��
�G�O�M�`�ʩm�Ω�^���l�ˡA�D�ۨ��K�¡B�o�X�c��a���Ĩ��A�O�H�h��
�O���O�F�H���I�ġC�γ\��K�ݬݧa�C(use plaster on ����)
long
);
        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",120);
        set("unit","�i");
        set("material","fur");
        }
        setup();
}

int do_use(object me,string arg)
{
        string type;
        if(!arg) return notify_fail("�Ϊk: use plaster on <����>�C\n");
        if(environment(this_object())!=me) return 0;
        if(sscanf(arg,"on %s",type)!=1) return notify_fail("�Ϊk: use plaster on <����>�C\n");

        if(type!="left_leg" &&
           type!="right_leg" &&
           type!="left_arm" &&
           type!="right_arm" &&
           type!="body" && 
           type!="head"
        )
	 return notify_fail("���ֻI�ĥu��K�b�ˤf(head,body,left_leg,right_leg,left_arm,right_arm)�W�C\n");

        if(me->is_busy() ) return notify_fail("�A�����ۡA�S���ŶK�ġC\n");
        if(me->query("wound/"+type) < 1) return notify_fail("�A��"+to_chinese(type)+"�èS���ˤf�C\n");
        message_vision("$N�@�⮳�_���ֻI�ĶK���ۤw"+to_chinese(type)+"���ˤf�A�uť�u���v�a�@�n�A�ˤf�o�X�@�Ѵc��......\n",me);
        me->receive_curing(type,2);
//        me->start_busy(1);
        destruct(this_object());
        return 1;
}

