#include <room.h>
inherit ROOM;

void create()
{
 set("short","�V�m��");
 set("long",@LONG
�o�̬O�@���s�諸�Ŧa�A�Ŧa�W���@�ǰV�m�Ϊ������A�����b�A
�v���ɷ|�b�o�䶰�X�V�m�A�H���I�~�Ӫ��I�Ǫ̡C
LONG
    );
   set("exits",([ 
       "east":__DIR__"room11",
       "west":__DIR__"room21",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
