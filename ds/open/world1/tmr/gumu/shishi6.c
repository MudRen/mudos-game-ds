#include <ansi.h>
inherit ROOM;

void create()
{ 
        set("short",HIC"�۫�"NOR);
        set("long", @LONG
�Ǥ��]�L�S�����B�A�A���Y����A�����ǳ��K�K�³ª��g���F�r��
�Ÿ��A�A�ݤF�@�|�A��ı�������ѡC�ǳ���n��ø�ۤ@�T�ϡA���P�Z�\
�L���A�����ӬݡA�˹��O�T�a�ϡC�۫ǥk�U��n���i�H���U(down)���C
LONG    );
        set("item_desc", ([
                "down" : HIB"�¥G�G���A�ݤ��u���A�A����T�w���쩳�n���(walk)�C\n"NOR,
        ]));
        set("exits", ([
                "up" : __DIR__"shiguan",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_look", "look");
        add_action("do_walk", "walk");
}

int do_look(string arg)
{
        object me=this_player();

        if ( arg =="map")
        {
                write(HIY"�A����ۨ��T�ϡA�ߤ����Ѥj�ߡA��Ө�ø�����O�X�Ӫ����D�C\n"NOR);
                me->set_temp("map", 1);
                return 1;
        }
         return notify_fail("�A�n�ݤ���H\n");
}

int do_walk(string arg)
{ 
        object me=this_player();

        if ( arg =="down")
        {
                if(!me->query_temp("map"))
                        return notify_fail("�A���}�Q���U���A���O�S�ݦA�T�A�S���^�F�}�C\n");
                write(HIM"�A�F����s�A�V���V�C�C�P�ɸ}�U��������A�t��������h�A��B���O\n�ùD�C�A���@�|�A�D���_�~�A���O�����V�U�C�U���F�����b�Ӯɨ��A�o\n�������F�A�u�O���o�]�����A��Z�ӧ�ť��F�F�F���n�A���W���S��\n��C�V�����V���A�ۻL�Ӹ��A���P�ݻ��C\n"NOR);
                me->delete_temp("map");
                me->move(__DIR__"anhe1");
                return 1;
        }
        return notify_fail("�A�b�۫Ǩ���ӿ�h�A�����p��O�n�H\n");
}

