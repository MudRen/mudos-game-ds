#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s��p-��_��"NOR);
 set("long",@LONG
�A��F�s��p����_��, �o�̸��L�a��@�˪��T��, 
�ߤ@���@�˪��O�A�����U��N�O�F�_�A�L�o, �@���A��
�F�_�A�L�����A�Q���U�h���İ�....
LONG
    );
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_climb","climb"); 
        add_action("do_jump","jump"); 
}
int do_climb(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1= load_object(__DIR__"ten32.c");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("���O�榡�G climb <��V> .\n");
        if( a!="south" )
                return notify_fail("�o�Ӥ�V�A�����L�h\n");
     if (a = "south")
    {
        message_vision(HIW"$N�q�s���W�u�۫n��ԾԹ��������h....�C\n"NOR,me);
        me->move(where1);
    }
        return 1;
}
int do_jump(string arg)
{        
        object me; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n�������H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "down") return 0;
        message_vision(HIR"$N�ۻ{���\\�F�o�K���U�@�������U�@���I�I\n"NOR ,me); 
        me->move("/open/world1/whoami/birdarea/en1.c");
        message_vision(HIW"$N�I�i���@���\\�A�q"NOR+YEL"�s��p"NOR+HIW"���U�A$N�~�M�@�v�L��..\n"NOR ,me); 
        return 1;
}

