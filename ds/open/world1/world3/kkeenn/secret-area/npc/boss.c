#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�ȩ�����" , ({ "boss" }));
        set("long",
        "�L�O�o�@�a��������A�L�������������U�ȤH�C\n"
        "�A�i�H�εn�O(register)�ӦV�L�n�O�ж��D\n"
        );
        set("chat_chance",9);
        set("chat_msg",({
  (: command,"smile" :),
  (: command,"bow" :),
  (: command,"say �z�n����" :),
  (: command,"say �Ф��n�b���j�n�ټM..." :),
}));
        set("inquiry",([
   "��J" : "��J�@���@�n400�T�q�l���ڳ��I\n",
]));
        set("no_fight",1);
        setup();
}

void init()
{
    add_action("do_register","register");
}

int do_register(string arg) //  sleep
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( !arg || sscanf(arg,"for %s",c)!=1 )
                return notify_fail("�A�n�����n�O����O�H( register for sleep)\n");
        switch(c) {
        case "sleep":
                if( me->query("bank/future") < 400 )
                        return notify_fail("�A���������C(400)\n");
                me->add_temp("sleep",1);
                me->add("bank/future",-400);
                message_vision("$N�I���F$n��J���O�ΡA�`�@400���C\n",me,ob);
                command("nod "+me->query("id"));
                me->move(__DIR__"../waiter2.c");
        break;

        default:
                write("�A�n��J(sleep)�ܡH\n");
        break;
        }
        return 1;
}

