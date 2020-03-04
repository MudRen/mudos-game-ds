#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("���p�G" , ({ "waiter" }));
        set("long",
        "�L�O�o�@�a�������p�G�A�L�������������U�ȤH�C\n"
        "�A�i�H�έq(bespeak)�ӦV�L�q�@�ǪF��D\n"
        );
        set("chat_chance",9);
        set("chat_msg",({
  "���p�G��A��: �ȭ��жi�жi !\n",
  (: command,"smile" :),
  (: command,"bow" :),
  (: command,"say �ȭ��z�n��" :),
  (: command,"say �аݬO�n�����٬O�n��J�O�H" :),
}));
        set("inquiry",([
  "����" : "����(bespeak)�@�� 100 �����I\n",
  "��J" : "��J�@���@�n 300 ������I\n",
]));
        set("sell_list",([
  "/obj/example/dumpling" : 6,
  __DIR__"obj/bag": 6,
  __DIR__"obj/winebag": 6,
        "/open/world1/tmr/wujian/npc/obj/iron-hoe.c": 30,
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
    if( this_player()->query("id") == "phoenix" && !userp(this_player()) )
    {
        command("kick "+this_player()->query("id"));
        this_player()->move("/open/world1/cominging/area/bnorth.c");
    } 
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_bespeak","bespeak");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "���p�G������A��: �ȭ��жi�жi  !\n");
                        break;
                case 1:
                        say( "���p�G�V�A���л��G�������s�O�����W���C\n");
                        break;
        }
}

int do_bespeak(string arg) // rest & sleep
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( !arg || sscanf(arg,"for %s",c)!=1 )
                return notify_fail("�A�n��p�G�q���������O�H(bespeak for {rest|sleep})\n");

        switch(c) {
        case "rest":
                if( !me->can_afford(100) )
                        return notify_fail("�A���W���������C(100���)\n");
                me->add_temp("rest",1);
                me->receive_money(-100);
                message_vision("$N�I���F$n�������O�ΡA�`�@���@�ʦh����C\n",me,ob);
                command("nod "+me->query("id"));
        break;

        case "sleep":
                if( !me->can_afford(300) )
                        return notify_fail("�A���W����������C(300���)\n");
                me->receive_money(-300);
                me->add_temp("sleep",1);
                message_vision("$N�I���F$n��J�@�����O�ΡA�`�@�T�ʦh����C\n",me,ob);
                command("nod "+me->query("id"));
        break;

        default:
                write("�A�n����(rest)�٬O��J(sleep)�O�H\n");
        break;
        }
        return 1;
}

