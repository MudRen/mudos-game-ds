#include <ansi.h>
//updated 26/12
inherit ROOM;

void create()
{
        set("short", HIC"ST�CBuilding�IE&O"NOR);
        set("long", @LONG
�ݨ��ܦh�H�b�ƶ��A�A�~�o�{�o�̬OSaint���X�J�Ҥj�ӡA���ܦh�H�b
�ƶ��L���A�ݨӥL�̬O�Q�^�m���˪��C�P�ɤ]���ܦh�ӤH�a�ۤ@�]�]�j�j
�p�p���U���ӽ�A�i�Q�Ӫ�Saint�O�@�Ӽ��x�������C
LONG    );
        setup();
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"train.c",
  "north":__DIR__"dst17.c",
]));
        set("light",1);
}

void init()
{
        add_action("do_show","show");
}

int valid_leave(object me, string dir)
{
        if( dir == "south" )
        {
                if (!me->query_temp("pass_enter"))
                        message_vision("�j�h��M��U��$N�d�F�U�ӡA��M�s���t���T�_�G�u�S���q���Ҫ��A�ֳ����i�H�X�h�I�v\n",me);
                else 
                {
                        message_vision("�b�Ǫ�����H���D�G�u�жi�жi�I�I�v\n",me);
                        me->set_temp("pass_enter",0);
                        return 1;
                }               
        }
        return ::valid_leave(me, dir);
}

int do_show(string arg)
{
        object who;
        who=this_player();
        if( !objectp(present("passport", who)) ) return 0;
        if(arg != "�q����" && arg !="passport" ) return 0;
        message_vision("$N�q�U�l�̮��X�A�������ҷӵ�����H���ˬd�C\n",who);
        if (who->query_temp("pass_enter")) return 1;
        who->set_temp("pass_enter",1);
        message_vision("����H�J�Ӧa�ݤF��$N��W�������ҷӡA���D�G�u�o��$N�ä��O�����,�жi�C�v\n",who);
        return 1;
}

