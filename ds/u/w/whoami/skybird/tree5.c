#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�|");

 set("long",@LONG
�A�V�}�U�ݤF�@��, �u���o�Ӥp�|�W��������~�����h�F
�ܦh, �i���o�̩Ҩ��L���H��h, �A���G�b�_�軷�B�ݨ�F�@��
�p��, �Ӧb�F��o���G���@�˰����X�_�����, �A�ߩ��@��, ��
�Ӥ��|�N�O�Ѥѥj��a....?
LONG);
 set("exits",([ "west":__DIR__"tree3",
                 "north":__DIR__"tree7",
                 "northeast":__DIR__"tree9",
    ]));
 set("objects", ([__DIR__"npc/woodguard" : 2+random(3),
    ]));
 set("no_clean_up",0);
 set("outdoors","forest");
 setup();
}

int valid_leave(object me, string dir)
{
   me = this_player();
    if (present("wood guard",environment(me)) && 
     ( (dir=="northeast") ))
       {
        message_vision("�ѱ��@��ϥΨ���צ�F�F�_�V���D���E\n",me);
        message_vision(YEL"�ѱ��@��ϻ��R$N�Q�L�h�H�I���N�n�ݧA���S���o�ӥ��ƤF�I�I\n"NOR,me);
       }
    else return ::valid_leave(me,dir);

}

