#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("���p�G" , ({ "waiter" }));
        set("long",
        "�L�O�o�a�������p�G�A�ݥ��S����ư����ˤl�C\n"
        "�A�i�H��(bespeak for qk)�ӦV�L�q��\n"
        );
        set("chat_chance",9);
        set("chat_msg",({
  "���p�G��A��: �ȭ��жi�жi !\n",
  (: command,"tsk" :),
  (: command,"�n�֣� ~ ~" :),
  (: command,"say �ȭ��z�w�w����" :),
  (: command,"say �аݭn�𮧶ܡH" :),
}));
        set("inquiry",([
  "��" : "��(qk)�@�� 300 �����I\n",
]));
        set("sell_list",([
  "/obj/example/dumpling" : 6,
  __DIR__"obj/bag": 6,
]));
        set("no_fight",1);
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy","buy");
        add_action("do_bespeak","bespeak");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "���p�G���y��A��: �ȭ��жi�Ч�  !\n");
                        break;
                case 1:
                        say( "���p�G�V�A���л��G�������H�B�ɬO�̦��W���C\n");
                        break;
        }
}

int do_bespeak(string arg) // qk
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( !arg || sscanf(arg,"for %s",c)!=1 )
                return notify_fail("�A�n��p�G�q�жܩO�H(bespeak for qk})\n");

        switch(c) {
        case "qk":
                if( !me->can_afford(300) )
                        return notify_fail("�A���W����������C(300���)\n");
                me->receive_money(-300);
                me->add_temp("qk",1);
                message_vision("$N���F$n�𮧪����A�T�ʿ��C\n",me,ob);
                command("ok "+me->query("id"));
        break;

        default:
                write("�A�n��(qk)�ܡH\n");
        break;
        }
        return 1;
}

