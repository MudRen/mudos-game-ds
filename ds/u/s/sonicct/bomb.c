#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�w�ɬ��u"HIR"�]���}�ҡ^"NOR,({"time bomb","bomb"}));
        set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long","�o�O�@���w�ɬ��u�A������ɷ|���z�C\n");
                set("no_give",1);
                set("no_sell",1);
                set("value", 2500);
        }
        setup();
}

void init()
{ 
        object me = this_player();    
        if( me->environment() ) return;
        add_action("do_use","use");
}

int do_use(string arg)
{
        int bomb;
        object me,obj;
        me  = this_player();
        obj = this_object();

        if( arg == "on" )
        {
                if( me->is_busy() ) return notify_fail("�A���ʧ@�٨S�������C\n");
                if(obj->query("bomb/time") >1 ) return notify_fail("�o�w�ɬ��u�w�g�b�ϥΤF�C\n");
                tell_object(me,"�w�ɶ}�l�C\n");
                me->start_busy(2);
                call_out("add_time",1,me);
                return 1;
        }
        else return 0;
}

int add_time()
{
        int i,bomb,which;
        object me, *ppl;
        me=this_player();
        ppl = all_inventory(environment(me));
        i = this_object()->query("bomb/time");
        which = random(sizeof(ppl));

        if( i > 60 )
        {
                if( !living(ppl[which]) ) which = random(sizeof(ppl));
                if( ppl[which] == me ) which = random(sizeof(ppl));
                message_vision(HIR"���M�I�u���㶩���v���p�a�_�몺�j�j�¤O�A��$N����V�g���ӥh�C\n"NOR,ppl[which]);
                message_vision(HIR"�u��$N�Q���u�F�����Y�g�y�C\n"NOR,ppl[which]);
                ppl[which]->receive_damage("hp",5000+random(101));
                destruct(this_object());
                return 1;
        }
        else {
                bomb = 60 - this_object()->query("bomb/time");

                this_object()->set("bomb/time", i+2 );
                this_object()->set("name","�w�ɬ��u"+HIR+"�]"+chinese_number(bomb)+"��^"NOR);

                call_out("add_time",1,me);
        }
}
