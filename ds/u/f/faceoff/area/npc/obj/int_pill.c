#include <ansi.h>
inherit ITEM;
void delay(object me);
void create()
{
        set_name(HIG "�z�q����" NOR,({"int pill","pill"}) );
        set("long",
"�o�O�Ѥѱ����ŷҤ��h�[�H��}���]�ƯM�H�Ӧ�, �ۤѱ�������, ���ѱ��ҳ�\n"
"�}���i��, �ڻ��A�U��i�N���z����!\n"
);
        set_weight(700);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",2000);
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
                return notify_fail("�A�w�A�U�F!�C\n");

        message_vision("$N�q�h�̮��X�@�������A�U�C\n",this_player() );
         tell_object(this_player(),HIY "�A���Mı�o�@�Ѽ���ĤW���F�ޡI�I\n" NOR);
        this_player()->add_temp("apply/int",2); //���[int 
        this_object()->set("do_eat",1);
        this_object()->set("no_drop",1);
        this_object()->set("value",50000);
        this_object()->set("no_sac",1);
        this_object()->set("no_give",1);
        call_out("delay",200,this_player() );     //���[�ݩʺ����ɶ�

        return 1;
}

void delay(object me)
{
        if(!me) return;
          tell_object(me,"�A��ı���F�ޤ@�}�H��ĤW! ���G�����ĮĤw�L�C\n" );
        me->add_temp("apply/int",-2);
       destruct(this_object() );
}
