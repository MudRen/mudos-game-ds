#include <room.h>
inherit ROOM;
void create()
{
 set("short","�w�q��");

 set("long",@LONG
�o�̬O�w�q�䪺�y��B, �o�̰��F�\�h����, �u�H�̥��b
�V�O�a��賨�쪺���h�U��, �b�X�Y����������W�U�}�B,
�A���G�ݨ캮��Ī��b���R�E
LONG
    );
 
 set("exits",(["south":__DIR__"kus2",
              ]));
 set("objects",([__DIR__"npc/worker" : 2,
     ]));
 set("outdoors","land");
 setup();
}           

