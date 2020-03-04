#include <ansi.h>
inherit ITEM;

void open_war(object me,object ob);
void callzombie();
void end_war();
int query_zombie(); 
string *zombie=({"acheron_zombie","new_zombie","skeleton_zombie","shiver_zombie","hate_corpse",
"oascure_zombie"});

string *place=({"zk1","zk2","zk3","zk4","zk5","zk6","zk7","zk8","zk9","zk10","zk11","zk12",
"zk13","zk14","zk15","zk16","zk17","zk18","zk19","zk20","zk21","zk22","zk23"});

void create()
{
        set_name(WHT"�ʨ�  �j�O"NOR,({"fong-evil gravestone","gravestone"}) );
        set_weight(200000);
        set("long",@LONG

�o�O�@�y�Q���j�Ѫ��۸O�A�W�����貪�w���A���ѡA�ݨӫإߪ��ɶ��w�g���[�C
�۸O�W���O��j�����J�i�ʦ~���ͧ@�áA�s�^�ľԡA�ʩ����U�A�����H�A
�H�s�|�z���ɱҤ��A�Ϩ�{���A�Y�i�����A���Ʊ��}�ƨo�C �j
�۸O�W�����G�i�H��Ǥ���F��(putting)

LONG);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�y");
                set("no_get",1);
                set("no_sac",1);
                set("value", 20000);
        }
        setup();
}

void init()
{
        add_action("do_putting","putting");
}

int do_putting(string arg)
{
        object me,ob,zombie,jade;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="jade in gravestone") 
                return notify_fail("�A�n�񤰻�F��?(putting xxx in xxx)\n");
        if(!objectp(jade=present("four-soul jade",me) ) )
                return notify_fail("�A���W�S���A�X�E�����𪺪F��C\n");
        if( ob->query("open_war") || query_zombie() )
                return notify_fail("�ø����w�g�����j�}�F�C\n");

        destruct(jade);
        message_vision("$N�N�|��ɩ�W�۸O�W�C\n",me);
        message_vision(HIC"\n�۸O�W���O�婿�M�o�G�������...\n"NOR,me);
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
HIY"\n    "+me->query("name") +HIR"����F���ߪ���q�A�ʨ����P�򩿵M����j��.......\n\n"
HIW"        �@�����ʦ~���ͩ��M�q�ø����`�B�}�g�ӥX.....\n\n\n"
HIB"��Ӷø����n�ɳ����}�}�A�;�M���I�I\n\n" NOR,users());           
          for(i=0;i<=12;i++)
        {
                g=new(__DIR__+"npc/"+zombie[random(sizeof(zombie) ) ] );
                g->move(__DIR__+place[random(sizeof(place))] );
        }

        call_out("callzombie",20);
        return;
}

void callzombie()
{
        object g;
        int i;
        //�L�ͤ�        
        g=new(__DIR__"npc/zombieking");
        g->move(__DIR__"zk12");
        //�ͱN
        g=new(__DIR__"npc/one_zombie");
        g->move(__DIR__"zk12");
        
        g=new(__DIR__"npc/corpse_demon");
        g->move(__DIR__"zk17");
        
        g=new(__DIR__"npc/corpse_demon");
        g->move(__DIR__"zk4");
        
        g=new(__DIR__"npc/lost_zombie");
        g->move(__DIR__"zk7");
        
        g=new(__DIR__"npc/lost_zombie");
        g->move(__DIR__"zk9");
        
        g=new(__DIR__"npc/barbaric_zombie");
        g->move(__DIR__"zk1");
        
        g=new(__DIR__"npc/barbaric_zombie");
        g->move(__DIR__"zk13");    
     
     call_out("end_war",180);
     return;
}

void end_war()
{
   object zombie;
      if( query_zombie() )
                call_out("end_war",30,0);
        else {  
           message("world:world1:vision",
HIW"\n\n                �ʨ���񪺳��������A����w�w����...\n\n"NOR
HIG"�L�ڦb���P�򪺸s�ͦ^�k�Фg�A��Ӷø����A�k�H�����w��F.....\n\n"NOR
           ,users());                 
           this_object()->set("open_war",0);
           }       
        return;
}

int query_zombie()
{
   object zombie;

        while( objectp(zombie=find_living("zombie-war-mob")) )
        {
                if( !environment(zombie) )
                {
                        destruct(zombie);
                        zombie = 0;
                }
                else break;
        }

        if( objectp(zombie) ) return 1;
        else return 0;
}















