#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�}��"NOR);
 set("long",@LONG
�o�Ӭ}�ޱq�|�P���۾��W�����������V�~�_�X���ݩ�o
�ӥ@�ɪ��H��A���Y�H���{�����A�|�B�}���A�٬O���ֱq�o
�̥X�h�a....
LONG
    );
 set("exits",([  "out":__DIR__"ten52",
    ]));
 set("objects", ([__DIR__"obj/cold_stone" : 1,
    ]));
set("no_clean_up",0);set("item_desc",([
       "����":HIW"�|�P�������H�N�����A�`�ȡA�ө����W���@�ө_�Ǫ���_��....?\n"NOR,
       "��_��":HIW"�ݰ_�Ӧ��G�O�@�ӳQ�ᵲ�b�����W������....�O������Ϊ��O?\n"NOR,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_pray","pray");
}

int do_pray(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten54");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("�A�n��������?\n");
        if( a!="����" )
                return notify_fail("���o�تF���?\n");
      if (me->query("level") > 27)
     {
        message_vision(HIW"$N�ۤߪ����U��������, ���M�@�}�����ƹL, $N���h�F�ܼv! \n"NOR,me);
          me->move(where1);
        return 1;
     }
     else 
     {
        message_vision(HIW"$N�ۤߪ����U���������A���������_�H�X�G�N$N�ᦺ!! \n"NOR,me);
        return 1;
     }

}


