// ming �� sky -by jangshow

#include <ansi.h>
#define IN_ROOM "/open/world1/acme/area/sky/room45"

inherit ITEM;
void create()
{
    set_name(HIW"�Ѧa����"NOR,({"ming-sky tree","tree"}));
        set("unit", "��");
        set("long",@LONG
����O�s���Ѧa�|�`���A��Ѧa�|�����y���Сz�����_����A
�o���𴲵o�ۯ��t�ե��A���A�Ԥ���Q�N(touch)���@�U�C
LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
        object me;
        string place;
        me=this_player();
        
        if(arg!="ming-sky tree" && arg!="tree" )
        {
                notify_fail("�A�n�N����?\n");
                return 0;
        }

        message_vision(HIW"$N�����N�F$n�@�U�C\n"NOR,me, this_object());

        if(CLUB_D->check_member("ming",getuid(me)) > 3 || CLUB_D->check_member("sky",getuid(me)) > 2 || wizardp(me))
        {
                        tell_room(environment(me),me->name()+"�����������L�v�L�ܤF�C\n",({me}));
                        me->move(IN_ROOM);
                        write(HIY"�y�ɤ@�}�j���N�A�a��Ѧa�|�`�������x�C\n"NOR);
                        tell_room(environment(me),HIC"��M���@�}�벴���~�A"+me->name()+HIC"�H�ۥ��~�X�{�󦹦a�C\n"NOR,({me}));
                        return 1;
                }
         else
        {
                write(this_object()->name()+""HIC"���G�{�ʤF�@�U�A�H�Y�S�^�_�F�쪬�C\n"NOR);
                return 1;
        }
}

