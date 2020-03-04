#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�U"NOR);
 set("long",@LONG
�o�̬O�ѱ��M�Ĥ@�����j�U, �q�`�n�Q�ױа�, �δx���n����
�ȤH, ���O�b����I, �A�o�{�o�̨èS���c�ت��˹�, ����O��²
�檺��O�f��, ���@�طɮ᪺�Pı.
LONG);
 set("exits",([ "southeast":__DIR__"pill6",
                "west":__DIR__"pill3",
    ]));
set("objects", ([__DIR__"npc/master" : 1,
                __DIR__"npc/birdguard" : 1+random(2),
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}

int valid_leave(object me, string dir)
{
   me = this_player();
    if (present("master",environment(me)) && 
     ( (dir=="southeast") ))
       {
        message_vision(YEL"�����]��$N�L�L�@���A���D�G�o��" + RANK_D->query_respect(me) + "�Яd�B�A�A�L�h�N�O���H��ͪ��ж��F�C\n"NOR,me);
       }
    else return ::valid_leave(me,dir);

}

