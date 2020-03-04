#include <ansi.h>
inherit ITEM;


void delay(object me);

void create()
{
        set_name(HIM "�I�G���" NOR,({"dab-aqua blood","blood"}) );
        set("long",
"�o�O�@���ѡu���s  �I�G�v��Ҿ��E�Ӧ�������A�������b�Ӥ�x�j�p�A\n"
"ť����妳�������ĥΡA�ѩ�u���s�@�I�G�v�֦��A������̧�O�֤��S��\n"
"�A�u�����γB�A�]�S�h�H���D�C\n"
);
        set_weight(1000);
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
                return notify_fail("�A�w�t�b�L�̤F�C\n");

        message_vision("$N�q�h�̮��X�@���x�۬���������t�b�f���C\n",this_player() );
         tell_object(this_player(),HIY "�A���Mı�o�A�����l�F���F�\\�h�I�I\n" NOR);

        this_player()->add_temp("apply/int",4); //���[int 
        this_object()->set("do_eat",1);
        this_object()->set("no_drop",1);
        this_object()->set("value",0);
        this_object()->set("no_sac",1);
        this_object()->set("no_give",1);
        call_out("delay",20,this_player() );     //���[�ݩʺ����ɶ�

        return 1;
}

void delay(object me)
{
        if(!me) return;
          tell_object(me,"�H�ۧA�f�����I�G��������ĤơA�A�����ʺC�C�a�^�_�F�C\n" );
        me->add_temp("apply/int",-4);
        me->receive_heal("hp",200);
          tell_object(me,HIY "�Aı�o�A���ͩR�ȫ�_�F�\\�h�C\n"NOR);
       destruct(this_object() );
}
