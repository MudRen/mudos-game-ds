#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�s���̹D"NOR);
 set("long",@LONG
�o�̤@���s���̹D��������^, �o���p�]�a������X�F
�@�j�O�C��, �ϱo�o�@�a���s���̹D�ݰ_���ٻᦳ�j���c�a
����H, �b�B��V�ͤ�K������, �s���̹D��o�J����S�R
���F�M��, �]�������L���ӮȬO�V�ӶV�֤F.
LONG
    );
 set("exits",([  "north":__DIR__"ten27",
                 "south":__DIR__"ten25",
    ]));
set("no_clean_up",0);set("item_desc",([
        "�C���O":HIG"�A��b�Q���X�o�˪��C���O�O�F���Ϊ�? �q�`�C��ߤ@���\\�άO���H�L�k��V(pass), ���L�o�̤��򳣨S����..\n"NOR,
    ]));

set("no_clean_up",0);
set("outdoors","land");
 setup();
}
void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me,where1;
        string a;
        me = this_player();
       where1 = load_object(__DIR__"ten41");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("�A�n��L����?\n");
        if( a!="�C���O" )
                return notify_fail("�A�����M�F��? �o�̨S���o�تF��!\n");
        message_vision(HIW"$N���M�@���ਭ���h�F�ܼv....\n"NOR,me);
      tell_object(me, HIR"�A�@���p�߳Q�C�󵹳ζˤF!\n"NOR);
     me->receive_damage("hp",30);
          me->move(where1);
        return 1;
}

