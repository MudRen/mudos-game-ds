#include <ansi.h>
#include <path.h>
inherit NPC;
// int sort_user(object ob1, object ob2);
void create()
{
        set_name("�ʪ��޲z�H��",({"animal controller","controller"}) );
        set("long",@LONG
�@�ӭt�d�޲z�ʪ��餺���ʪ����u�@�H���A�L�}�Ӻ��ؼ~���A���дo�����C
LONG
);
        set("age",50);
        set("level",1);
        set("attitude", "peaceful");
        set("race","�H��");
        set("gender", "�k��" );
        set("chat_chance",10);
        set("chat_msg",({
        (:command("sigh"):),
      //  (:command("say ooxx�H"):),
        }) );
                set("talk_reply","�A�����ڤ@�I�p��(help)�ܡH\n");
                set("inquiry/help","�o�X�Ѧ��@�ǰʪ��ۤv�ȤF�X�ӡA�A�i�H���ڮ��^���̶ܡH\n");
        setup();
       set_living_name("reward-war-animal");
}
void init()
{
        ::init();
        add_action("do_reward","reward");
add_action("do_nod","nod");
 //     add_action("do_gamelist","gamelist");
}
int do_nod(string arg)
{
      object me, net;
      me=this_player();
       say("�A�N���o�ӥh���ڧ�^���Ǥp�ʪ��a�C\n");
       say("���ڧ���A�ڷ|���A���S(reward)���C\n");
message_vision("�ʪ��޲z�H�����F$N�@�ӹq�lŢ�C\n",me);
        net=new(__DIR__"obj/net");
        net->move(me);
}
int do_reward(string arg)
{
        int i;
        object me,p;

        me=this_player();
        i=me->query("Find_An/animal");

        if(!arg) return notify_fail("�A�Q�n������S�H(exp)(popularity)\n");
        switch (arg)
        {
        case "exp":
        message_vision("$N�Q�n�g��ȡC\n",me);
        if (i<5) return notify_fail("�A�S�S���ڧ���ƥت��ʪ��D�D�D�Сš�\n");
        message_vision(HIY "$n�o��F1000�I�g��ȡC\n" NOR ,this_object(),me );
        me->add("exp",1000);
        me->add("Find_An/animal",-5);       
        break;

        case "popularity":
        message_vision("$N�Q�n�n��C\n",me);
        if (i<100) return notify_fail("�A�S�S���ڧ���ƥت��ʪ��D�D�D�Сš�\n");
        message_vision(HIY "$n�o��F�@�I�n��C\n" NOR ,this_object(),me );
        me->add("popularity",1);
        me->add("Find_An/animal",-100);
        break;

        default:
        return notify_fail("�S���o�س��S���C\n");
        break;
        }
        return 1;
}
/*
int do_gamelist()
{
        string str, *option;
        object *list,me;
        int i, j, ppl_cnt,opt_id;
        me=this_player();
        str = HIW "��  ���ʪ���^�m�̦h���u�W�ƦW \n" NOR;
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        list = users();
        list = sort_array(users(), "sort_user", this_object());
                ppl_cnt = 1;
                j = sizeof(list);
                while( j-- ) {
                        if( !environment(list[j]) ) continue;
                        if(!list[j]->query("Find_An/animal") ) continue;
                        if( me && !list[j]->visible(me) ) continue;             
          str = sprintf("%s%-30s%s",
           str,
              "��"+(string)ppl_cnt+"�W�G"+list[j]->query("name"),
              (string)list[j]->query("Find_An/animal")+"���C\n",
           );
                        ppl_cnt++;
                }
                
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        int ord;

        ord = ob1->query("Find_An/animal")-ob2->query("Find_An/animal");
        if( ord==0 )
                ord = (int)ob1->query_level() - (int)ob2->query_level();
        return ord;
}
*/


