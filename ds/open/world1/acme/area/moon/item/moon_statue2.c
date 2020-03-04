#include <ansi.h>
#define SECRET_ROOM "/open/world1/acme/area/moon/room8"
inherit ITEM;
void create()
{
    set_name(HIC"�߮Z�J��"NOR,({"Moon-goddess statue","statue"}));
        set("unit", "�y");
        set("long",@LONG
�o�O�뤧�@�کҳB��c���Ĥ@���c�D���J��--�߮Z�C��u���J�����Hı�o���G�o���J�����ۥͩR�O�C
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
        add_action("do_worship","worship");
}

int do_worship(string arg)
{
        object me;
        me=this_player();

        if(arg!="statue" && arg!="moon-goddess statue")
        {
                notify_fail("�A���j�z�ۦa�O�ýW�@�q�����Y�����ȡC\n");
                me->start_busy(1);
                return 0;
        }
        tell_room(environment(me),HIC+me->name()+"�@�۽����߮Z�J����A�ϩ�����o���ȯ��C\n"NOR,({me}));
        if(CLUB_D->check_member("moon",getuid(me)) > 1 || wizardp(me))
        {
                write(HIC"�A�@�۽����߮Z�J����A�ϩ�����o���ȯ��C\n"NOR);
                if(me->can_move(SECRET_ROOM))
                {
                        tell_room(environment(me),HIG+me->name()+"��M�����F�C\n"NOR,({me}));
                        write(HIR"���M���ӭI�ۥ��j���}���k�H�§A���L�ӡA�A�~���|�B�ö]�C\n"NOR);
                        me->move(SECRET_ROOM);
                        write(HIW"�A�o�{�ۤv���W�䧮�Ө�@�ӯ������a��C\n"NOR);
                        tell_room(environment(me),me->name()+"���Y���ޤ@�˨S�Y�S�����ĤF�L�ӡC\n",({me}));
                        return 1;
                } else
                {
                        write(CYN"���G����Ƴ��S�o�͡A���O�A���G�ݨ�߮Z�L���L�L�W���F�@�U!?\n"NOR);
                        return 1;
                }
        } else 
        {
                write(CYN"�A���G�ݨ�߮Z�L���L�L�W���F�@�U..\n"NOR);
                return 1;
        }
}

