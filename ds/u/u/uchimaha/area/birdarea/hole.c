#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���N�}");

 set("long",@LONG
�o�̬O�@�Ӧ��N�}, �̭��u���|�����N�b�s�s���s��, 
�ݼˤl�O�{�l�j�F, ���ǨS�ݨ���N, ��ӬO�X�h�����F,
�A���U�|�P, ���O��K�M���l, �a�W�٦��ǳ\���Ф�, ��
�ӨS�����򲧪��C

LONG
    );
 
 set("exits",(["out":__DIR__"bird4",
 
     ]));
 set("objects",([__DIR__"npc/eagle" : 4,
                 __DIR__"npc/eagle2" : 1,
     ]));
set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
