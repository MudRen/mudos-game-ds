#include <ansi.h>
inherit ITEM;


void delay(object me);

void create()
{
        set_name(HIR"�� �s �x" NOR,({"fire-dragon liver","liver"}) );
        set("long", @LONG
�o�O���s���xŦ�A���ۯ��_���\�ĸ����I�C
LONG
);
        set_weight(10000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",4500);
                set("unit","��");       
        }
        setup();
}


void init()
{
        add_action("do_eat","eat");
}

int do_eat(string arg)
{
        object env;
        string type,msg;

        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        if(! env = environment(this_object())) return 0;
        if(env !=this_player() && !this_object()->query("no_get")) return 0;
        if( this_player()->is_busy() )
                return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
        if(this_object()->query("do_eat") )
                return notify_fail("�A�Y�F�C\n");

        message_vision("$N�Y�U�@�����s�x�C\n",this_player() );
         tell_object(this_player(),HIR "�Aı�o�餺�@�}���� . . . �O�q�H�����W �I�I\n" NOR);
        this_player()->add_temp("apply/str",5);  
        this_object()->set("do_eat",1);
        this_object()->set("no_drop",1);
        this_object()->set("value",0);
        this_object()->set("no_sac",1);
        this_object()->set("no_give",1);
        call_out("delay",40,this_player() );     
        return 1;
}

void delay(object me)
{
        if(!me) return;
          tell_object(me,"���s�x�b�A�餺���ơA���U�譱�]�����^�_�C\n" );
        me->add_temp("apply/int",-10);
        me->receive_heal("hp",500);
          tell_object(me,HIR "�Aı�o�n�h�F�C\n"NOR);
       destruct(this_object() );
}

