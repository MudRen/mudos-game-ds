#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�@��"NOR, ({ "cracker" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�Ӭ��⪺�@���A�z���¤O�Q���C\n");
                set("unit", "��");
                set("value",0);
        }
        setup();
}

void init()
{ 
        add_action("do_bombing","bombing");
}

int do_bombing(string arg)
{
        object me,obj,test;
        test = new("/u/c/coffee/game/newyear/monster-beard");
        me = this_player();

        if( !arg ) return notify_fail("�A�n���֡H\n");
        if ((arg!="year monster")&&(arg!="monster")) return notify_fail("�@�����n���Ӷì�..= =\n");
        if(me->is_busy() ) return notify_fail("�A���b���A�S�ŰաC\n");
        if(!objectp(obj = present(arg, environment(me)))) return notify_fail("�o�̨S���o�تF��C\n");

        message_vision("$N�N�@���I�U�A�åB�ֳt�a�᩹$n�I\n",me,obj);

        if(!obj->query("monster-beard"))
        {
           message_vision(YEL"$n������F"+me->query("name")+"("+me->query("id")+")�@�}...\n"NOR,me,obj);
        }
        else 
        {
             if( random(40) > 30 )
             {
                message_vision(HIW"�~�~�Q�@������F�A�������q�s..�I\n"NOR,me);
                me->add("monster-beard",1);
                tell_object(me,HIC"�@�����z���¤O���~�~���T�~��A���F�@��Ž��A����W�C\n"NOR);
                test->move(environment(me));
//              destruct(obj);   //�[�F�o��monster�N�|����
             }
             else
            {
                message_vision(HIW "�~�~�o�{�F$N�Q�����L�A�榣�������@���A�ñN���㪺�@�����V$N�I�I\n"NOR,me);
                me->receive_damage("hp",500,this_object());
                me->start_busy(1);
            }
        }
 return 1;
}

