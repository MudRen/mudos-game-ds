// mumen.c �Ӫ�
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
        set("short", "�Ӫ�");
        set("long", @LONG
�A���L�F��a�A�o�{�ۤv�w���B�`�������A����X�X�A�H�N�G�H�C
�|�U�O�����p���}��a�A��a�a�q�ߵۤ@�y�@�H�����զ�y�����A��
�W�䪺���Y�w�g�Z��F�A�ݪ��X�ӳo�O�y�j�ӡC�ӫe�S���߸O�A�]�S��
���󪺼аO�C�ӦZ�O���˴˪��Q�L�j��A�󥭲K�Q����M���檺���椧
�N�C�Ӫ��Ȼ��Ӱ��A�����O�j�Ӭ��Ҧb�C�Ӫ��f�Q�@�����K�K���j���Y
(stone)�ʳ��o���@���z�C
    �j�ӶǤH���Ӥ����X����A������è���k�k���}���s�G�H���C�X��
�ַN���򪺻����A���ɤd��i���Z�צ�������@�ʱ��C�����d�����ӧ�
���C
LONG    );
        set("outdoors", "gumu");
        set("exits", ([
                "east"  : __DIR__"xuanya",
                "west"  : __DIR__"huangshalin",
                "north" : __DIR__"caodi",
                "south" : __DIR__"mudao01",
        ]));
        set("objects", ([
                __DIR__"npc/yufeng" : 2+random(2),
        ]));
        set("item_desc", ([
                "stone": "�o�O�����ۡA�Ȥ����U��W�U�A���������観�ۡ�"+YEL"���s��"NOR+"���X�Ӧr�C\n"
        ]) );
        setup();
}

void init()
{
        add_action("do_move", "push");
}

int do_move(string arg)
{
        object room, me = this_player();

        if( !arg || arg != "stone" )
        {
        return notify_fail("�A�n���ʤ���H\n");
        }
        if( !query("exits/south"))
        {
          return notify_fail("���s�ۤw�g���U�A�A�S���F��n���ʤF�C\n");
        }
        if((int)me->query_str()>33)
        {
                message_vision("$N���b���s�۫e�A���x�o�O���ʭ��s�ۡA�uť�o���s�ۧs�s�s�n�A�w�w�V�U���h�A�ʦ�F�Ӫ��C\n", me);
                delete("exits/south");
                if( !(room = find_object(__DIR__"mudao01")) )
                        room = load_object(__DIR__"mudao01");
                room->delete("exits/north");
                remove_call_out("reopen");
                  call_out("reopen", 600, me);
                tell_room(room,"�uť�o���s�ۧs�s�s�n�A�w�w�V�U���h�A�ʦ�F�Ӫ��C\n");
        }
        else
                message_vision("$N�յ۱��F�����ۡA���ۯ������ʡA�u�o�}�F�C\n", this_player());
        return 1;
}


void reopen()
{
        object room;

        tell_room(this_object(), "�uť�o���s�ۧs�s�s�n�A�w�w�V�W�ɥh�A��_�F�쪬�C\n");
        set("exits/south",  __DIR__"mudao01");

        if( !(room = find_object(__DIR__"mudao01")) )
                room = load_object(__DIR__"mudao01");
        room->set("exits/north", __DIR__"mumen");
        tell_room(room, "�uť�o���s�ۧs�s�s�n�A�w�w�V�W�ɥh�A��_�F�쪬�C\n");
}

