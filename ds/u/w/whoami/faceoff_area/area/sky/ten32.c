#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s��p-��n��"NOR);
 set("long",@LONG
�o�̴N�O�s��p����n��F, �A�i�H�ݨ�s�Ǧ��@�y�Y
���Y�{���ؿv��, ���L�ܩ��㪺����S�����q�V����, ����
���ܤ@�����g, ���F�@���a�b�Ť��������H�~, �N���򳣨S
���F, �ݨӳo�̤]�u��Ϊ�(climb)��....
LONG
    );

set("no_clean_up",0);set("item_desc",([
        "�ؿv��":HIG"�q�����P��, ��ò�Ӭ�, �j���O�@�y����������...\n"NOR,
       "����":HIG"�o���������A�Q����@�W�٦��񥦧�}�ª��F��, �ϱo�A�@�I�����|�Q�h��W�h(take on)...\n"NOR,
    ]));
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_climb","climb");
     add_action("do_take","take");
}
int do_climb(string arg)
{
        object me,where1,where;
        string a;
        me = this_player();
        where1=load_object(__DIR__"ten28.c");
      where = load_object(__DIR__"ten33.c");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
            
    return notify_fail("���O�榡�G climb <��V> .\n");
        if( a!="east" )
                return notify_fail("�o�Ӥ�V�A�����L�h\n");
     if (a = "east")
    {
        message_vision(HIW"$N�q�s���W�u�۪F��ԾԹ��������h....�C\n"NOR,me);
        me->move(where1);
    }
        return 1;
}

int do_take(string arg)
{
        object me,where1,where;
        string a;
        int x;
        me = this_player();
        x = me->query_skill("dodge") / 2+ me->query("dex") / 2 +random(20);
        where1=load_object(__DIR__"ten33.c");
      where = load_object(__DIR__"ten29.c");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "on %s", a )!=1 )
                return notify_fail("���O�榡�G take on <���~> .\n");
        if( a!="����" )
                return notify_fail("�o�Ӥ�V�A�����L�h\n");
        message_vision(HIW"$N�`�l�@�f��, �i�����������������h�C\n"NOR,me);
    if (x < 33)
    {
        tell_object(me,HIR"�A�@�ӥ���, �������p���ۯ멹�U�Y�h!!\n"NOR);    
        me->move(where);
    }
    else
    {
        tell_object(me,HIW"�A�Ӯ𪺤@���ਭ, ��n���b��������������, ���]�~�X�F�@���N��!\n"NOR);    
        me->move(where1);
    }
        return 1;
}
