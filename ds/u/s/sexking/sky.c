#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"�Ѱ�");
        set("long", @LONG
�A�w�Q�p�����H�G���F�Ѱ��..�A�ݨ�A���Ǧ��\�h�Ѩ�
�����������A�ݨ�F�C�q�����v..�Ԥ����Lsay hello �F 
�@�n..͢�ٹ�A���F�@��...���ۧA�}�l�e�t�U�Y........
LONG
        );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}
void init()
{
        add_action("do_fly","fly");
}

int do_fly(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="sky") return 0;
        message_vision(HIW"$N���I�W��M���F��ӯͻH�Ʀ��ѨϪ��Ҽ˭����F�I�I�C\n"NOR,me);
        me->move(__DIR__"workroom4");
        me->set_temp("the-sky",1);
        return 1;
}

