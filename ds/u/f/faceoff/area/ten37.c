#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�C�۸�");

 set("long",@LONG
�o�̤��M�O�C�۸����@�q, �̾ڧA���g��, �C����G�O�ѱ�
���N���, ���L�A��ܦ�, �o�{��ӭn�h�ѱ��M�Ĥ@�����H�]��
���b��, �����D�L�̥h������?
LONG
    );
 set("exits",([	"north":__DIR__"ten38",
		"south":__DIR__"ten36",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}