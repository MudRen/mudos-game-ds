#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�m�Z��");
 set("long",@LONG
�A�o�{�e���C�@�Ӫ����W�F�����`��, �ݨӤ��i��A����
���F, �A�ݨ�A�����e���@�ӳC�Τj�~�b���娭��, ���λ�, 
�L�N�O��D�F....
LONG
    );
 set("exits",([ "south":__DIR__"ten7",
    ]));
 set("objects", ([__DIR__"npc/bleader" : 1,
		  __DIR__"npc/ileader" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
