//�o�ط|�Ȯɥ[�ݩʪ����A��O�ӯS�O�~�A�u���t�~�g�F�C
#include <ansi.h>
inherit ITEM;
void delay(object me);

void create()
{
        set_name(HIC"���_�ĤY"NOR,({"powerful pill","pill"}) );
        set("long","�o�O�@�ɵ}�����Ī��C\n");
        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",100000);
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

        message_vision("$N�q�h�̮��X�@���x��"HIR"����"NOR"���ĤY�t�b�f���C\n",this_player() );
        tell_object(this_player(),HIW"�A���Mı�o�A���O�q�W�j�F���֡I�I\n"NOR);

        this_player()->add_temp("apply/str",10); //���[str
      this_player()->add_temp("apply/int",10);
      this_player()->add_temp("apply/dex",10);	    		    
      this_player()->add_temp("apply/con",10);	    
        this_object()->set("do_eat",1);
        this_object()->set("no_drop",1);
        this_object()->set("value",0);
        this_object()->set("no_sac",1);
        call_out("delay",300,this_player() );     //���[�ݩʺ����ɶ�

        return 1;
}

void delay(object me)
{
        tell_object(me,HIW"�H�ۧA�f�������_�ĤY�����ĤơA�A���O�q�C�C�a�^�_�F�C\n"NOR);
        me->add_temp("apply/str",-10);
      me->add_temp("apply/int",-10);
      me->add_temp("apply/dex",-10);
      me->add_temp("apply/con",-10);	
        destruct(this_object() );
}
