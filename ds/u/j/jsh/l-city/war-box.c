inherit ITEM ;
#include <ansi.h>

void create()
{
        set_name(HIR"�Ԫ���"NOR,({"war box","box"})); 
        set("unit","��");
        set("base_unit","��");
        set("needaward",3); 
        set("no_drop",1);
        set("no_give",1);
set("long","�o�ʾԪ��ҥΪ����l[gowar]�C\n");
        setup();
}

void init()
{
        add_action("do_gowar","gowar");
}

int do_gowar(string arg)
{
        object  me,np;
        me = this_player(); 
        if(!arg || arg!="now") return notify_fail("�n�{�b�o�ʾԪ�?[now]\n"); 
        {
        message_vision(CYN"\n$N�V�Ԫ������I�F���A���ܰ��ܰ����Ť��I\n"NOR,me);
        message_vision(HIR"\n�Ԫ��������z�}�I�C\n"NOR,me);
        message("world:world1:vision",HIR"\n                                /\n"
                                         "                               / \n"
                                         "                              /  \n"
                                         "                             /   \n"
                                     +HIR"                            ��   �y�����ۡ�z�ѪŪx�_�{�G���� \n" 
                                     +HIG"\t"+me->name(1)+""+HIB"�����V�}ù���žԡA�}�ҤF�}ù�������Ԫ��I�I\n" 
                                     +HIW"\t�}ù�h�L�I�_�F�T�ϡA�������Q�G�D�����ƥ��}�I�I\n"
                                     +HIM"\t�ƥH�U�p���}ù�h�L�A�q�����n�_��F�i�ӡI�I\n"+NOR,users());   
        tell_room(me,HIB"�A�����}�l�鱫�E�E�E��ӬO�T�Ϸd�����E�E�E\n"NOR);

        me->add_busy(60);
        np=new(__DIR__"npc/sword-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/blade-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/axe-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/fork-soldier");
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/sword-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/blade-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/axe-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/fork-soldier");
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        destruct(this_object());
        }
    return 1; 
}

