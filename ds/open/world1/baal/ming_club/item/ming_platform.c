#include <ansi.h>
#define SECRET_ROOM "/open/world1/baal/ming_club/mingsaint"
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
        tell_room(environment(me),me->name()+"��ʵ۸t���аO�A�|�P�X�{�@�}�����C\n",({me}));
        if(CLUB_D->check_member("ming",getuid(me)) > 4 ||CLUB_D->check_member("sky",getuid(me)) >3|| wizardp(me))
        {
                write("�A��ʵ۸t���аO�A�|�P�X�{�@�}�����C\n");
                if(me->can_move(SECRET_ROOM))
                {
                        tell_room(environment(me),me->name()+"�b�����������F�C\n",({me}));
                        write("�b�����P�V���A�|�P�������}�l�ҽk�_��..\n");
                        me->move(SECRET_ROOM);
                        write("�A�Ө���иt�a�C\n");
                        tell_room(environment(me),me->name()+"��M�X�{�b�o�̡C\n",({me}));
                        return 1;
                } else
                {
                        write("�A��ʸt���аO�A����O���S�o�͡C\n");
                        return 1;
                }

        } else 
        {
                write("�A��ʸt���аO�A����O���S�o�͡C\n");
                return 1;
        }
}

