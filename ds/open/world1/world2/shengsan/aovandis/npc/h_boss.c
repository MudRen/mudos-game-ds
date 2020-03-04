#include <ansi.h>
inherit NPC;

void make_mark();

void create()
{
        set_name("���]�ѪO",({"hotel's boss","boss"}) );
        set("long","�L�O�o�����]���ѪO�A�ܶ}�������A�����b�����Ӥ���l��C\n�p�G�A�Q���u�G�y��J sign in ���ᱵ�ۿ�J dusting�z\n");
        set("age",55);
        set("level",10);
        set("race","�H��");
        set("gender","�k��");
        set("evil",-5);         // ���c�� -5 (�������c, �t���})
        set("exp_point",0);     // �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
                                // 0 <= exp_point <= 9
                                // ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: make_mark :),
        }) );
        set_skill("dodge",10);
        set_skill("block",10);
        set_skill("parry",10);
        set_skill("unarmed",10);
        set("inquiry",([
            "���u" : "�A�Q���u�@�I�H��ڴN��F�A�A�u�n�V�ڵn�O(sign in)�A�N��}�l���u(dusting)�F�C\n[�������D:�u��]\n",
            "�u��" : "�ڭ̳o�ॴ�u�O���@�ɳ̦n�Ȫ��F�A�u�n���Ӥ@���N���G�Q�T�����@�C\n[�������D:���]\n",
            "���" : "�A�u�n���X(say)����A�ڴN�|���A����u���C\n",
        ]));
        set("talk_reply","�A�Q���u�ܡI�H�ܦn�Ȫ��@�C");
        setup();
        add_money("dollar",50);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_sign","sign");
        add_action("do_say","say");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if(random(2)) command("say �z�n!�w����{!!");
}
void make_mark()
{
        object *enemy, ob;
        command("say �z�I�ϩR���I");

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        if(!ob) return;

        if( this_object()->query("helpready/"+ob->query("id")) )
                return;

        command("say "+ob->query("name")+"�A�A�O���]���C");
        ob->add_temp("quest/aovandis",1);       // �N�ۭt�������H���W�аO
        this_object()->set("helpready/"+ob->query("id"),1);     // �P id ����

}
int do_sign(string arg)
{
        object me;
        me=this_player();
        if(arg != "in") return notify_fail("�A�nñ����H\n");
        if(me->query_temp("dusting") > 0)
        {
          tell_object(me,"�A�w�g�b���u�F�C\n");
          return 1;
        }
        else {
          message_vision("$N��ۮ��]�ѪO���D�G�ڭn���u�C\n",me);
message_vision("���]�ѪO���F�ӥ��l��$N�A$N�b�W�Yñ�F�W�A�A�\\�W�F�@�Ӥj�Y���C\n",me);
          me->set_temp("dusting",1);
          return 1;
        }
}
int do_say(string arg)
{
        int i;
        object me;
        me=this_player();
        i=me->query_temp("addmoney");
        if( arg == "���" )
        {
          if(me->query_temp("addmoney") == 0 ) return notify_fail("���]�ѪO��A���G�A�S�S���a�N�n��ڻ���H\n");
          if(me->query_temp("addmoney") > 0 )
          {
            message_vision(GRN"$N���G���\n"NOR,me);
            message_vision("���]�ѪO�q�d�i���X�F"+ i*20 +"�T������$N�C\n",me);
            me->receive_money(i*20);
          me->delete_temp("addmoney");
          }
          return 1;
        }
}
