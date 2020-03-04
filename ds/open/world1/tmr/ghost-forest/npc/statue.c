#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me,object ob);
void end_war();

string *ghost=({"ghost6","ghost9","ghost12","ghost4","dog"});

string *place=({"forest2","forest3","forest4","forest5",
        "forest6","forest7","forest8","forest9","forest10",
        "forest11","forest12","lea","shrine","tree_up"});

int query_ghost();  // added by Cominging ��K�ˬd��.

void create()
{
        set_name("����  �L�k��",({"ghost statue","statue"}) );
        set_weight(200000);
        set("long",@LONG
�o�O�@�L�������K�ت��۹��A�貪�w�����鸨�A�ݨө�m�b���ɤ�w
�[�C�۹��Y�������в��A���ܥջȾԥҡA���@�V���ɴҡA�ʦp���u�C�L�k
����@���ءA�ܥض����H�����ۭt���Pı�C
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�L");
                set("no_get",1);
                set("no_sac",1);
                set("value", 20000);
        }
        setup();
}

void init()
{
        add_action("do_kneel","kneel");
        add_action("do_blooding","blooding");
}

int do_kneel(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg !="statue") return 0;
        message_vision("$N�����q�q�µL�k�����F�U�h�C\n",me);
        me->set_temp("kneel_ghost",1);
        return 1;
}

int do_blooding(string arg)
{
          object me,ob, blood;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="statue") return 0;
        if(!objectp(blood=present("dab-aqua blood",me) ) )
                return notify_fail("�A���W�S������������F��C\n");
        if( ob->query("open_war") || query_ghost() )
                return notify_fail("���_�˪L�w�g�����v�h�F�C\n");

        destruct(blood);
         message_vision("$N�N�@�������٦b�L�k���W�C\n",me);
        message_vision(CYN"\n�@�D���~�q�L�k���Ⲵ���ĤW��.....\n"NOR,me);
        ob->set("open_war",1);
        call_out("open_war",3,me,ob);
        return 1;
}

void open_war(object me,object ob)
{
        int i;
        object g;

        if( !ob->query("open_war") ) return;
        message("world:world1:vision",
HIW"\n    "+me->query("name") +HIW "�Ѷ}�F�`�I�w�[���ʦL�A����Ѫũ��M�嶳���G.......\n\n"
HIC"        �@�}�}�ɹp�n�T�q�˪L�`�B���L�k���ǤF�}��.....\n\n\n"
HIR"��y���_�˪L�n�ɸs�����{�A�۱��@���I�I\n\n" NOR
,users() );
        //����
        g=new(__DIR__+"ghostking" );
        g->move(TMR_PAST+"ghost-forest/shrine" );
        for(i=0;i<=12;i++)
        {
                g=new(__DIR__+ghost[random(sizeof(ghost) ) ] );
                g->move(TMR_PAST+"ghost-forest/"+place[random(sizeof(place))] );
        }

        call_out("end_war",180);
        return;
}

void end_war()
{
        object ghost;

        if( query_ghost() )
                call_out("end_war",30);
        else {
                message("world:world1:vision",
HIY"\n\n                ���誺����g�Ӥ@�D��������~���İ��_�˪L�`�B...\n\n"NOR
CYN"    ���E�b���_�˪L�W�誺�嶳���F�}�ӡA��y�˪L�S�^�_���ɪ��I�R�F.....\n\n" NOR
                ,users() );
                this_object()->set("open_war",0);
        }       
        return;
}

int query_ghost()
{
        object ghost;

        while( objectp(ghost=find_living("ghost-forest-war-ghost")) )
        {
                if( !environment(ghost) )
                {
                        destruct(ghost);
                        ghost = 0;
                }
                else break;
        }

        if( objectp(ghost) ) return 1;
        else return 0;
}
