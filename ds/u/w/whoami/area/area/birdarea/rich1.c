#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","�I�v�j��");
 set("long",@LONG
�A�Ө�F�y�������}�@�����I�����e, �A���e�O�@�����j��
�����j��, ����٦��@��i���Z�����۷�l, �b�A�}�䦳�@�ƤQ
�����۶�, �۶��s���ۤj���E
LONG
    );
 
 set("exits",(["south":__DIR__"village15",
               "enter":__DIR__"rich2",
              ])); 
 set("objects", ([__DIR__"npc/dog" : random(3),
               ]));
 setup();
 create_door("enter","�����j��","out",DOOR_CLOSED,"nokey");
}        

int valid_leave(object me, string dir)
{
   me = this_player();
    if (present("watchdog",environment(me)) && 
     ( (dir=="enter") ))
       {
        message_vision(HIY"\n�ݪ�����$N�g�p�F�X�n�A�ݨӤ��ѨM�e�O�i���h�F�E\n"NOR,me);
       }
    else return ::valid_leave(me,dir);

}

