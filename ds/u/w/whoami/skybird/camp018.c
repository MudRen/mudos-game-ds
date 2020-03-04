#include <ansi.h>
inherit ROOM;

void callmob();
void end_war();
void start_war();

string *soldier=({"sword_soldier","pike_soldier","axe_soldier","leader","leader2"});

void create()
{
        set("short", "�T�s��p��");
        set("long", @LONG
�o�̭��ٺⰮ�b�A�ܤ֤��|�L���ż�A�ƭӪ��j�_�������
��������w�ժ��o�X�n���A�o�̳Q�j�y���u�u�_�X�����𵹧˱o
�����j���A�A���G�i�H�q�X���Ѫ��D��O����C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"camp019",
]));
        set("objects", ([
       __DIR__"mob/soldier_cook" : 1,
                ]));

        set("light",1);
        set("no_clean_up", 0);
        setup();
}

void start_war()
{
        int i,x;
        object g;
        x = random(24);
        if(x<3) x=3;
//�p���o(bandit's lackey)  -> 15 ��
//����(bandit)             -> 10 ��
//�g��(brigand)            ->  7 ��
//�p�Y��(ringleader)       ->  5 ��
//----------------------------------
//�X�p(total)              -> 37 ��

/*
                message("world:world1:vision",
        HIW"\n\t�Q�U�s��s��@���Ӵ��A��y�s��{�Y�ū��E\n\n"  NOR
                ,users() );
*/

        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[0]);
        g->move(__DIR__+"camp0"+x);
        g->set_temp("auto_kill"); 
        }
        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[1]);
        g->move(__DIR__+"camp0"+x); 
        g->set_temp("auto_kill"); 
        } 
        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[2]);
        g->move(__DIR__+"camp0"+x);
        g->set_temp("auto_kill"); 
        } 
        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[3]);
        g->move(__DIR__+"camp0"+x);
        g->set_temp("auto_kill"); 
        } 
        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[4]);
        g->move(__DIR__+"camp0"+x);
        g->set_temp("auto_kill"); 
        } 
     call_out("end_war",40);
     return;
}

void end_war()
{
        object npc;
        object e,s,n,w;
        if(objectp(npc=find_living("Ten-mount_soldier") ) )
        {
                 if(!environment(npc)) destruct(npc);
                  call_out("end_war",30,0);
        }
        else { 
/*                message("world:world1:vision",
        HIW"\n\t�Q�U�s��s��@���Ӵ��A��y�s��{�Y�ū��E\n\n"  NOR
                ,users() );
*/
          this_object()->delete("Ten-mount_soldier");
        }
return;
}

