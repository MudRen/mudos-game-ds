#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�b�Ť�");
        set("long", @LONG
�A���B�b�b�Ť��A����÷�����M�ֳt�a�ԵۧA���W���...
�|�g���������ֳt�b�A���ǭ��u��.....
LONG
        );
        set("item_desc",([
        "����÷��":"�@�������⪺÷���A�ݤ��X�ӬO������谵�����C\n",
        "����":"��t���h���������A�A���G�o�{�s�����B�p�s�}�H�I\n",
        ]) );
        set("world", "past");
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="�s�}") return 0;
        message_vision("$N���@�f��A��}�F����÷���A���s���@�Ӭ}�f���h�I�I�C\n",me);
        me->move(__DIR__"hole");
    me->set_temp("jump-hole",1);
        return 1;
}

