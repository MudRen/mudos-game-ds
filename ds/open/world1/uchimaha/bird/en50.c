#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");
 set("long",@LONG
�A�Ө�F�F�_�A�L���`�B, �]�N�O�ҿת��˪L�h�A
��, �A�Pı��o�̪�����M���e���j���ۦP, ���@�ظ�
������^, �o�����q�����.

LONG
    );
 
 set("exits",(["west":__DIR__"en51",
               "northeast":__DIR__"en49",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
