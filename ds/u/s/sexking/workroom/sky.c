#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"�Ѱ�");
        set("long", @LONG
�A�Q���b�p�����H�G���F�o�Ӧa��..���䦳�ܦh�Ѩ�...
�A�����������ݨ�F�C�q�����v..�٤�����ı����͢ say hi.....
LONG
        );
        set("item_desc",([
        "�p�����H�G":"�@���H�H���F��..ť���i�O�@�H�����ˡC\n",
        ]) );
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

int do_jump(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="sky") return 0;
        message_vision(HIW"$N���W��M���_�F�ͻH�A���ѨϤ@�˧ּ֪����U���h�I�I�C\n"NOR,me);
        me->move(__DIR__"workroom2");
        me->set_temp("the-sky",1);
        return 1;
}
