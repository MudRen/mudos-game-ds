#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��ø��f");

 set("long",@LONG
�o�̬O�@�B��ø��f, ���_�|�q�������᪺�ѱ��M�Ĥ@��
, ���F�h�O�L�̮���ĤީM�Ĥ誺�ѱ����Ķ�, ����h�|�^��
�ϸz�D.
LONG
    );
 set("exits",([	"north":__DIR__"ten36",
		"west":__DIR__"ten26",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}