#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
 �o�̬O�ѱ��Ъ�����, �A���U�F�|�P, �o�{���|��
 �Τj�z�۰����ѱ��۬W, �a�O�M�Ѫ�O�]�O�j�z�۰���,
 �b�j�U���������@�i�۴�, �W�����ۤ@�ӤH, �A�Q�g��
 �����r���H���ӴN�O�L�F�C

LONG
    );
 
 set("exits",(["west":__DIR__"bird18",
              ]));
 set("objects",([__DIR__"npc/fon" : 1,
     ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 set("light",1);
 setup();
 replace_program(ROOM);
}           
