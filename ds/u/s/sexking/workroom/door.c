#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"��g�ɪ��G�D");
        set("long", @LONG
�A�Q���l��o�Ӧa���o�{�o�̪��@���ƪ����O��g��....
���򤣥i�઺�Ƴo�̳��o�ͤF..�p�G�����I���}�o��....
�s�A�]�i��|��g��......
LONG
        );
        set("item_desc",([
        "��g�ɪ��G�D":"�@�ӷ|�O�H��g���G�D..�A�w�֧�g�F��C\n",
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

int do_fly(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="sky") return 0;
        message_vision(HIY"$N��M��F�秾�ѩ�ӧ��N�����F�A�I�I�C\n"NOR,me);
        me->move(__DIR__"workroom2.c");
        me->set_temp("the-door",1);
        return 1;
}



