#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(MAG"�o�ܥ��J�O"NOR, ({"dove chocolate","chocolate"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "�����U�j�W�ӬҦ��b�檺���J�O�A�f���Q�����n�f�C\n");
                set("unit", "��");
                set("value", 10000);
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
        if( !arg ) return notify_fail("�A�n�Y����?\n");
        if( arg == "chocolate" )
        {
                if( me->is_busy() ) return notify_fail("���L���A�еy��I\n");
                me->set("hp",me->query("max_hp") );
                me->set("mp",me->query("max_mp") );
                me->set("ap",me->query("max_ap") );
                message_vision(HIW"$N�Y�U�@��$n�C\n", me, this_object() );
                tell_object(me, "���ֺ����A������O�ҫ�_�F!!\n");
                if(random(2))
                {
                        tell_object(me, HIY"���J�O���A���a���@�i�N�m��!!\n"NOR);
                        new(__DIR__"bliss-ticket")->move(me);
                } else tell_object(me, HIB"�ΤO�@�r�A�L�گ}�F�A�����S�F��...\n"NOR);

        me->start_busy(1);
        call_out( (: destruct(this_object()) :), 1);

        return 1;
        } 
}

