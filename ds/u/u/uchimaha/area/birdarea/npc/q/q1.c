#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���I�a",({ "man" }));
        set("long","�@�ӱq�~�a�Ӫ����I�a�A�ݰ_�Ӧn��������ߨơC\n");
        set("level", 10);
        set("age",44);
        set("chat_chance", 8);
        setup();
        add_money("coin",200);
}

int talk_action(object me)
{
        object ob;
        ob = this_object();
        if( !query_temp("pe") )
             message_vision(ob->name()+"��$N���G"+RANK_D->query_respect(me)+"�i���i�H���ڮ���"HIR"���H�� �E��"NOR"���W����??\n",me);                             
        return 1;
}

int accept_object(object who, object ob)
{
        object tob, a;
        tob = this_object();
        if( ob->query("id")!="fox fur" || query_temp("pe") ) return 0;

        command("thank "+who->query("id"));
        command("say �u�O�ӷP�§A�F�A"+RANK_D->query_respect(who)+"�I\n");
        who->add("exp", 8000);
        set_temp("pe",1);
        tell_object(who,HIW"�A�o�� 8000 �I�g��ȡC\n"NOR);
        call_out("delay",600,this_object());
        set("long","�@�ӱq�~�a�Ӫ����I�a�A���N�ۥL��W���֡C\n");

        return 1;
}

void delay(object tob)
{
delete_temp("pe");
        set("long","�@�ӱq�~�a�Ӫ����I�a�A�ݰ_�Ӧn��������ߨơC\n");
        return;
}


