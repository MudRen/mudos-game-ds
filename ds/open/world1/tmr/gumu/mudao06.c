// mudao06.c �ӹD
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"�ӹD"NOR);
        set("long", @LONG
�o���O�j�Ӥ����ӹD�A�|�P�K���z���A�ɵ��٤W���t���O���A�A��
�j�j����X��V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X�o�ƬO�����A��
�H�q����X�@���_�ءC�O���Ӧb�C�۾��W�A�{�{�ۺѫիժ����I�C
    �F��۾��W���G���@���t��(door)�C
LONG    );
        set("exits", ([
                "west" : __DIR__"zhongting",
        ]));
        set("item_desc", ([
        "door" : "�@���p�����۪��A���ȷȪ����S�����C�A�{�u�ݤF�ݡA�o�{���䪺�۾��W���G��������s(press button)�i�H�}���C\n",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_an", "press");
}

int do_an(string arg)
{
        object room, me = this_player();

        if( !arg || arg != "button" )
        {
                message_vision("�A�b�۾��W�ë��@��A���F�@��ǡAԣ�]�S�N�ۡC\n", me);
                return 1;
        }
        if( query("exits/east"))
        {
                return notify_fail("�۪��w�g�O�}�ۤF�F�C\n");
        }
        if( me->query_skill("unarmed", 1) > 10)
        {
                message_vision("$N���b�۪��e�A�]�����b�������F�@�U�A�۪��s�s�T�ۡA�w�w���}�F�C\n", me);
                if( !(room = find_object(__DIR__"houting")) )
                        room = load_object(__DIR__"houting");
                set("exits/east", __DIR__"houting");
                room->set("exits/west", __DIR__"mudao06");
                tell_room(room,"�uť�o�۪��b�s�s�n���Q�w�w���}�C\n");
                remove_call_out("close");
                call_out("close", 5, me);
        }
        else
                message_vision("$N�յۦb�۾��W���ӫ��h�A�i�O�۪��������ʡC\n", me);
        return 1;
}

void close(object me)
{
        object room;

        tell_room(this_object(), "�۪��w�w�a���W�A��_�F�쪬�C\n");
        delete("exits/east");
        if( !(room = find_object(__DIR__"houting")) )
                room = load_object(__DIR__"houting");
        room->delete("exits/west");
        tell_room(room,"���𪺷t���w�w�a���W�F�C\n");
}

