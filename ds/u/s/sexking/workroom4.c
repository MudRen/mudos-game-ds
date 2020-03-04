#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", " "HIC"��g����"NOR" ");
        set("long", @LONG
�o�̬Osexking��g��֪��ɫ�ҥ𮧪��a��,
��M�p�G�A�]�Q�ոլݧ�g������...�N��(sleep)
�b�o�ݬݧa..�a�O���ܦh�a�赹�A�Σ��C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"workroom3",
        ]));
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
      setup();
}
void init()
{
        add_action("do_sleep","sleep");
}
int do_sleep()
{
        object me;
        me=this_player();
        message_vision(HIW "$N�N��A���������F��g���̪��W��...�C\n" NOR, me);
        message_vision(HIC "$N�P������B�B�D�D���ܵΪA...\n" NOR, me);
        message_vision(HIR "$N��M�o�{�ۤv�}�l��g...����g���Pı�u�n...\n" NOR, me);
        me->start_busy(8);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
       call_out("sleepup",15,me);

return 1;
}

void sleep1(object me)
{
        if(!me) return;
    tell_object(me,HIY"�A��g�F�@�}�l��֤F...��O�A�N����ᦱ���@�ӧ�g���ҼˡA���W�F��....\n"NOR);
        me->receive_heal("hp",me->query_con()*6);
        me->receive_heal("ap",me->query_con()*6);
        me->receive_heal("mp",me->query_int()*3);
        return;
}

void sleep2(object me)
{
        if(!me) return;
        tell_object(me,HIG"���ۧA�N�}�l��g�����ۧ�g����.......\n"NOR);
me->receive_heal("hp",me->query_con()*6);
        return;
}

void sleepup(object me)
{
        if(!me) return;
        message_vision(HIW"$N�������C�}����...�u��$N�f���y�����y���O..�n�n���C\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/sleeping");
        me->receive_heal("hp",me->query_con()*6);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*3);
        return;
}

