#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"�xŦ"NOR, ({ "monster liver" ,"liver" }));
        set("long",@LONG
�o�O�@�����򴲵o�۴H�𪺺G�զ�xŦ�A���G�O�ۦW�K���T�a�u�@�~
�u�N��v����Ŧ�C�A���b�x�߸̡A��ı�o�㰦��ֳQ��ʤF�A�����Y�b�L
�̷|�O��˴����C
LONG
        );
        set("weight",50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("value",1);
        }
        setup();
}
void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        string type,msg;
        object ob,me,env;
        me = this_player();
        ob = this_object();
        if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
        if( me->is_busy() )
                return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
        if( ob->query("do_eat") )
                return notify_fail("�A�w�g�t�b�L�̤F�C\n");
        if(me->query_temp("super_used") )
                return notify_fail("�A�L�̥��t�۪F��A����A��F��i�h�F�C\n");
        /*
        me->receive_heal("hp", me->query("max_hp") - me->query("hp"));
        me->receive_heal("mp", me->query("max_mp") - me->query("mp"));
        me->receive_heal("ap", me->query("max_ap") - me->query("ap"));
        */

        if( me->is_fighting() ) me->start_busy(2);
        message_vision(HIW "$N�q�h�����X�F�@�����G�O�ʪ���Ŧ�t�b�L��..\n" NOR,me);
        if( me->query_skill("force") < 50 )
        {
                tell_object(me,CYN"�A�餺���u�𩿵M�j�áA�A�L�k�J�������I�I\n" NOR);
                message_vision(HIR "$N�@�n�G�s�A���L�̪��F��R���A�H�Y�R�X�F�X�f�A��A�y�W��ⳣ�S�F...\n" NOR,me);
                me->receive_damage("hp",me->query("max_hp")/2 );
                me->receive_damage("ap",me->query("max_ap")/2 );
                me->start_busy(2);
                destruct(ob);
                return 1;      
        } 

        if(!ob->query("super_used") && !me->query_temp("super_used") )
        {
                tell_object(me,
                HIG"�A�L�̪��@�}�H��M�A�����l�椬�V�X�A�ϱo�A���骺���A�ﵽ�\\�h�C\n" NOR
                );
                message_vision(HIW "$N�K���@�n�A�����g�X�@�D�p�q���{������I�I\n" NOR,me);
                me->add_temp("apply/dex",2);
                me->add_temp("apply/str",2);
                me->add_temp("super_used",1);
                ob->set("super_used",1);
                ob->set("do_eat",1);
                ob->set("no_drop",1);
                ob->set("no_sac",1);
                ob->set("no_give",1);
                ob->set("no_sell",1);
                call_out("delay",600,me);     //���[�ݩʺ����ɶ�
        }
        return 1;
}

void delay(object me)
{
        if(!me) return;
        message_vision(CYN"$N�B�P�@�n�A���G�]�U�F����F��....\n" NOR,me);
        me->add_temp("apply/str",-2);
        me->add_temp("apply/dex",-2);
        me->delete_temp("super_used");
        destruct(this_object());
}
