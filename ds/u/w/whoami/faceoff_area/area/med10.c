#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short",HIR"�ū�"NOR);

 set("long",@LONG
�o�̬O�ūǪ����Y�F, ���F�N�|���}�o�ӷū�, �ө���N�|
�^��ūǷ�, �ӳo�̪��ūשM���|���䧹���@��, ���A��ѱ�
���޳N���Ѩ�F�\�h.
LONG
    );
 set("exits",([ "east":__DIR__"med11",
		"west":__DIR__"med7",
		"north":__DIR__"med9",
    ]));
create_door("east","�˪�","west",DOOR_CLOSED);
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}
