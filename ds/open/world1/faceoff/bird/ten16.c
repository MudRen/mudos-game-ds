#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
�o�ǬO�뤤���s���, ���F��ܰ����q�s�U���갣�s�骺�x
�L���ӿv����, ��D�`����T, �ӥB��W���\�h���b�����̭��i
�H�V�~�g�b, �ݨӫ�����i�h�K.
LONG
    );
 set("exits",([	"south":__DIR__"ten6",
		"north":__DIR__"ten17",
    ]));
 set("objects", ([__DIR__"npc/yleader" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}
