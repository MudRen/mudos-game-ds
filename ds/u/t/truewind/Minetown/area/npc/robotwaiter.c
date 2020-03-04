inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("���F�G��" , ({ "robot waiter","robot","waiter" }));
        set("long",
        "�����b�q�l�b�׫e�A�Ȧ⪺������ۧA...�C\n"
        "�A�i�H�έq(book)�ӦV�L�q�b�ץ𮧡D\n"
        );
        set("title","�����H");
        set("chat_chance",9);
        set("chat_msg",({
  "(�س�...�س�...)\n",
  (: command,"stare" :),
  (: command,"bow" :),
  (: command,"say (�س�...)������ݭn�O...�n�𮧽Х�ú�O..." :),
}));
        set("inquiry",([
  "��" : "�𮧤@���@�n 200 �q�l��(�س�...)�C\n",
]));
        set("no_fight",1);
        setup();
}

void init()
{
        object ob=this_player();
        ::init();
        if( userp(ob) && this_object()->visible(ob) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_pay","pay");
        return;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        command("say (�س�)������ݭn��??");
                        break;
                case 1:
                        command("pat $N");
                        break;
        }
        return;
}

int do_pay(string arg) // rest & sleep
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( arg )
                return 0;
        if( !me->can_afford(200) ) return notify_fail("�A���W���������C(200�q�l��)\n");
        if( me->query_temp("mine/tent")) return notify_fail("(�س�)�A�w�g�I�L���F�A�жi�h�𮧡C\n");
        me->set_temp("mine/tent",1);
        me->receive_money(-200);
        message_vision("$N�I���F$n�b�׶O�Ψ�ʤ��C\n",me,ob);
        command("say ���±z���f�U�A�бz�ۦ�i�J�𮧧a�C");
        return 1;
}
