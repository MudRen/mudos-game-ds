#include <ansi.h>
#include <path.h>

#define GOD_DIR "/u/m/moonhide/westarea/"  // Add by -Acme-
inherit ITEM;

void open_war(object me,object ob);
void end_war();

string *god=({"ba","lin","ean","mon","sha",
          "poo","dang","unin","liu"});

string *place=({"room2","room1","startroom","room3",
        "room4","room5","room6","room7","room8",
        "room9","room10","room11","room12","room13",
        "room14","room15","room"});

int query_god();  

void create()
{
        set_name(HIY"�L  �W  ��  �L  ��"NOR,({"god-king statue","statue","god"}) );
        set_weight(5000000); 
        set("long","�@�L�Q�ت����B�A�J��, ��L�J���W�W�Y�Y, �ݨӦ~�N�w�[���F�C\n");
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�L");
                set("no_get",1);
                set("no_sac",1);
                set("value", 90000);
        }
        setup();
}

void init()
{
        add_action("do_firing","firing");
}

int do_firing(string arg)
{
        object me,ob,god,torch;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="statue") return 0;
        if(!objectp(torch=present("torch",me) ) )
                return notify_fail("�A���W�S������C\n");
        if( ob->query("open_war") || query_god() )
                return notify_fail("�L�ƪ��ѻ��٦b���ݤW�C\n");

        destruct(torch);
        message_vision(HIW"$N�I�M"HIR"����"HIW"�A���L�W�ܴL����F�L�h�A�ܴL�������z�� . . . \n"NOR,me);
        message_vision(HIY"\n\n�@�D�D�����~�q�ѤW���F�U�� . . .\n"NOR,me);
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
HIR"\n         "+me->query("name") +HIW "�Ѷ}�F�L�W�ܴL�����W�����K.......\n\n"
HIC"        �i~�Q��~�j: ����ť�O ! ! �N���ݤW���H.....\n\n\n"
HIR"         �q        �q        ��        �� ! !\n\n" NOR
,users() );
//        g=new(__DIR__"pill" );  mark by -Acme-
        for(i=0;i<=12;i++)
        {
                g=new(__DIR__"pill"   );
                g->move(GOD_DIR+place[random(sizeof(place))]);   // Add by -Acme-
                g=new(__DIR__+god[random(sizeof(god))]);   // Add by -Acme-
                g->move(GOD_DIR+place[random(sizeof(place))]);   // Add by -Acme-
        }

        call_out("end_war",180);
        return;
}

void end_war()
{
        object god;

        if( query_god() )
                call_out("end_war",30);
        else {
                message("world:world1:vision",
HIC"\n\n\t         ������ݪ����n...�ǹM�F��ӥ@�� \n\n"NOR
HIW"       .................���ѻ�˺G��.............\n\n" NOR 
HIG"       ................�H�ɦ��M�L���i��............\n\n"NOR                ,users() );
                this_object()->set("open_war",0);
        }       
                return;
}

int query_god()
{
        object god;

        while( objectp(god=find_living("god-war")) )
        {
                if( !environment(god) )
                {
                        destruct(god);
                        god = 0;
                }
                else break;
        }

        if( objectp(god) ) return 1;
        else return 0;
}

