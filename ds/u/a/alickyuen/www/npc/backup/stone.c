#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�h�L�M", ({"antiquity guard","guard"}) );
        set("long", @LONG
    �j�N�ӳ������@�äj�x�A�Q�j�ѯ������k�N�ᤩ�ë��ͩR�P¾�d�A
�õL����b�j�Ӹ̰���u�@�u�@�A���ɥ��󴱾����j�Ӫ������C�h�L�M
���O�d�즨�������j�H���A�S����ı���|�h�ΡA��w�����ߤ��Ӭ��ߴM�`
�L���������C
LONG);
        set("age", 100);
        set("level",20);
        set("attitude", "aggressive");
        set_temp("apply/armor", 300);
        setup();
}

void init()
{       
        object ob;
        ::init();
        if(!this_object()->visible(this_player())) return;
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{ 
        //object me=this_player();
        if( !ob || environment(ob) != environment() ) return; 
        {
                        message_vision(HIR"�h�L�M�۹D�G�x�������ӳ��I�ǩR�ӡI\n"+NOR,ob);
                        this_object()->kill_object(environment(ob));
        }
}

