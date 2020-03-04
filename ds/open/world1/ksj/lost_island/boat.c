#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name("�ۦ�", ({"stone boat","boat"}) );
        set("long",@LONG
    �@���ۻs���L���p��A�����a�b����A���ѯ��_���O�q�ϥ��B�b
�����W�A�A�i�H�յ۷f�W�ۦ�(ferry)�C
LONG
        );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1);
        set("unit", "��");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
        add_action("do_ferry","ferry");
}

int do_ferry(string str)
{
        object me,z;
        me=this_player();
 
        if(!str || str!="boat") return 0;
        if(me->query_temp("ride"))
        {
         write("�A���y�M����h�F�X�B�A�n�����@�N�W�ۦ�..\n");
         return 1;
        }
        if(!objectp(z=present("sea stone",me) ) )
        return notify_fail("�ۦ��M��������A�A�L�k�W�h�C \n");
        destruct(z);
        message_vision(
        HIC"\n$N���W�o�X�@�}�Ŧ���~�A�ۦ�]�I�������o���A�H�Y$N�n�W�F�ۦ�C\n"NOR
        HIC"\n$N���W���Ѯ��ۭ��X�O�b�ۦ઺�p���O�W�A�ۦ๳�O�o��ʤO�����®��W��p�I\n"NOR,me);
        me->move(__DIR__"stone-boat");
        destruct(this_object());
        return 1;
}
