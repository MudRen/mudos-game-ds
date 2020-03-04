#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", " "HIC"�j�D����"NOR" ");
        set("long", @LONG
�A�w�g�i��j�D���̭��F�A�o�̿@���}�}�A�|�P���Q�Q���A���ѩ�
�����ū׫ܰ��A�@�ɵL�k�A���]���٤����N�����w(suds)�i�h�A��
�O���A�A�����ū�A�b�N�����w(suds)�i�h�ɨ��w�����֧a�C
LONG
        );
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_suds","suds");
        add_action("do_up","up");
}

int do_suds()
{
        object me;
        me=this_player();
             if( me->query_temp("suds") <= 0 )
        {
                write("�p�G�Q�b�ɨ��@���w�����������ܽХX�h�A�I�@���b�a�I\n");
                return 1;
        }
        if(me->query_temp("is_busy/sudsing"))
        {
                write("�A�w����b�ӵΪA�F�A�w���Q���䥦�ƤF�C\n");
                return 1;
        }
    
        message_vision(HIW "�A�ּּ֧֪��]�V�j�D���ǱN�}���F�i�h�C\n" NOR, me);
        tell_object(me, HIR "�_��A�P��ܿS���p�C�C���A���F.....\n" NOR );
        tell_object(me, HIB "�A�N���l�����D���̡A�P��L�񪺵ξA�P...\n" NOR );
        me->disable_player_cmds("�A�w����b�ӵΪA�F�A�w���Q���䥦�ƤF�C\n");
        me->set_temp("is_busy/sudsing","�A�w����b�ӵΪA�F�A�w���Q���䥦�ƤF�C");
        me->start_busy(10);
        call_out("suds1",3,me);
        call_out("suds2",8,me);
        call_out("sudsup",15,me);

return 1;
}

void suds1(object me)
{
        if(!me) return;
    tell_object(me,HIY"�ѩ��b�O�ӵΪA�F..�A�A�Ԥ������b��ǧߤ�A�W���W�F��....\n"NOR);
        me->receive_heal("hp",me->query_con()*6);
        me->receive_heal("ap",me->query_con()*6);
        me->receive_heal("mp",me->query_int()*3);
        return;
}

void suds2(object me)
{
        if(!me) return;
        tell_object(me,HIG"������ı���A�w�i�J�F�ֵּL�񪺥@��...�A�����εۤF...\n"NOR);
me->receive_heal("hp",me->query_con()*6);
        return;
}

void sudsup(object me)
{
        if(!me) return;
        message_vision(HIW"$N��M�C�}�����A���G�ܺ������ˤl�A���ǳƯ�(up)�_�����}�D���C\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/sudsing");
        me->receive_heal("hp",me->query_con()*6);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*3);
        me->add_temp("suds",-1);
        return;
}
int do_up()
{
        object me;
        me=this_player();
        if( me->is_busy() )
        return notify_fail("�A�٦b�����௸�_��...\n");
        message_vision("$N�q�D�����F�_��..�@�I�������ˤl�C\n",me);
        me->start_busy(2);
        me->move(__DIR__"boy_suds");

    return 1;
}
       if( me->query_temp("suds") <= 0 )
        {
                write("�p�G�Q�b�ɨ��@���w�����������ܽХX�h�A�I�@���b�a�I\n");
                return 1;
        }
