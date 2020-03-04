#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�ѷ�" , ({ "old yang","yang" }));
        set("long",
        "�L�O�o�@�a�������D�A�L�Q���ԳҪ��۩I�۫ȤH�A\n"
        "�o�a���L�w�g��~�ܦh�~�A��O�Ѥf�O�F�A�ӥB��\n"           "��C�G�A�]���Ӧ������ȵ�ö�����C\n"
        "�Y�A�����N�i�H�έq(bespeak)�ӥh�ϥμp�Цۻs�Ʋz\n"        
        "���L�O�o�ǳƦn���ơD\n"
        );
        set("chat_chance",9);
        set("chat_msg",({
  "���p�G��A��: �ȭ��жi�жi !\n",
  (: command,"smile" :),
  (: command,"bow" :),
  (: command,"say �ȭ��z�n��" :),
  (: command,"say �аݭn�I�Ǥ���ܡH" :),
}));
        set("inquiry",([
  "�ۻs�Ʋz" : "�ۻs�Ʋz(bespeak)�@��3000�����I\n",
  "cook" : "�ۻs�Ʋz(bespeak)�@��3000�����I\n",
  "�a�կP" : "�A���a�դj�L�r�A������]�O�ک��̪��`�ȡC",
  "���ѷ�" : "�ѫ����ѷݤ]�ܳ��w���H���ڭ̭q�Ʋz����",]));
        set("sell_list",([
  __DIR__"item/food/wealfish-soup": 6,
  __DIR__"item/food/freshsha-soup": 6,
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
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_bespeak","bespeak");
}

void greeting(object ob)
{
 if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "�ѷ�������A��: �ȭ��жi�жi  !\n");
                        break;
                case 1:
                        say( "�ѷ��V�A���л��G�������Ʋz�O�������W���C\n");
                        break;
        }
}

int do_bespeak(string arg) // cook
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( !arg || arg!="cook" )
                return notify_fail("�A�n�q����O�H(cook)\n");
        if( !me->can_afford(3000) )
                return notify_fail("�A���W���������C(3000���)\n");
                me->add_temp("cook",1);
                me->receive_money(-3000);
                message_vision("$N�I���F$n�ϥμp�Ъ��O�ΡA�`�@���T�d�h����C\n",me,ob);
                command("nod "+me->query("id"));
                return 1;
}






