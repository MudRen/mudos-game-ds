#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"��g������");
        set("long", @LONG
�A�w�g�Q�l���g�������F...�u������ѱۦa��...�����˯�
�q�q�D����.........
�A�Pı��ۤv�֭n�����F.....
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
        message_vision(HIW"$N��M�۳�X�@�Ӭ~�����~�F�Ӿ��N���������F�I�I�C\n"NOR,me);
        me->move(__DIR__"workroom2");
        me->set_temp("the-shit",1);
        return 1;
}

