#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
�A�{�b�Ө쪰�W�ު�����, �A�~���i�o�ӥ޸�, 
�A�N�Q��{���d�o�֭n�R�X�ӤF, ��M���@�s�������
�����W�§A�ĹL��, �����C���m�ժ����A�o�r��, �A�u
�n�w���Y�ָ�L�̾԰��F�C
 
LONG
    );
 
 set("exits",(["out":__DIR__"en10",
               "north":__DIR__"en12",
           ]));
 set("objects",([__DIR__"npc/fox3" : 3,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
