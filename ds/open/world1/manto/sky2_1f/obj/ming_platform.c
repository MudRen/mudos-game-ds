#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"�t���x"NOR,({"The Platform of Holy Fire","platform"}));
        set("unit", "�y");
        set("long",@LONG
�W�����@�t���аO(fire)�n���i�H���(turn)
LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_turn","turn");
}

int do_turn(string arg)
{
        object me;
        
        me=this_player();
        if(arg!="platform")
        {
                notify_fail("�A�n�र��?\n");
                return 0;
        }
        tell_room(environment(me),HIR""+me->name()+"��ʵ۸t���аO�A�|�P�X�{�@�}�����C\n"NOR,({me}));
                write(HIR"�A��ʵ۸t���аO�A�|�P�X�{�@�}�����C\n"NOR);
                write(HIR"�b�����P�V���A�|�P�������}�l�ҽk�_��..\n"NOR);
                tell_room(environment(me),HIR""+me->name()+"�����v�b�������@�}�ҽk�C\n"NOR,({me}));

        return 1;
}

