#include <ansi.h>
#define SECRET_ROOM "/open/world1/acme/area/moon/room7"
inherit ITEM;
void create()
{
    set_name(HIY"�߮Z�J��"NOR,({"Moon-goddess statue","statue"}));
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
        add_action("do_kneel","kneel");
}
int do_kneel(string arg)
{
        object me;
        me=this_player();

        if(arg!="statue")
        {
                notify_fail("�A���j�z�ۦa�O�ýW�@�q�����Y�����ȡC\n");
                return 0;
        }
        tell_room(environment(me),me->name()+"�@�۽����߮Z�J����A�ϩ�����o���ȯ��C\n",({me}));
        if(CLUB_D->check_member("moon",getuid(me)) > 1 || wizardp(me))
        {
                write("�A�@�۽����߮Z�J����A�ϩ�����o���ȯ��C\n");
                if(me->can_move(SECRET_ROOM))
                {
                        tell_room(environment(me),me->name()+"��M�����F�C\n",({me}));
                        write("���M���ӭI�ۥ��j���}���k�H�§A���L�ӡA�A�~���|�B�ö]�C\n");
                        me->move(SECRET_ROOM);
                        write("�A�o�{�ۤv���W�䧮�Ө�@�ӯ������a��C\n");
                        tell_room(environment(me),me->name()+"���Y���ޤ@�˨S�Y�S�����ĤF�L�ӡC\n",({me}));
                        return 1;
                } else
                {
                        write("���G����Ƴ��S�o�͡A���O�A���G�ݨ�߮Z�L���S�X�F�@�ӷL��!?\n");
                        return 1;
                }
        } else 
        {
                write("�A���G�ݨ�߮Z�L���S�X�F�@�ӷL��..\n");
                return 1;
        }
}
