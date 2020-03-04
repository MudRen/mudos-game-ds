#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�s���̹D-�_�f"NOR);
 set("long",@LONG
�s���̹D�b�o�̴N�����F, �A���e�u�ѤU�@���l��, ��
�s���̹D�쥻�b���ਤ�u�ݱo��@����t, �ϩ��b�����H��
�o�̴��g�O�g�Ӫ��D�n�~�|, �ӥu�����e���s���o�R�R��ť
....
LONG
    );
 set("exits",([    "south":__DIR__"ten26",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me,where;
        string a;
        me = this_player();

        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("�A�n�������?\n");
        if( a!="�s��" )
                return notify_fail("�o�̨S���o�تF�赹�A��\n");
        message_vision("$N�b�s���W���۸������P�V�e��A\n"
                        +"���M�@���ਤ���h�F���v....?!\n",me);
        me->move(where);
        return 1;
}

