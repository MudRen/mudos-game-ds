#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�ݯ}���۶�");
        set("long", @LONG
�j�P���n�_�߾ԳӤ@���A�A�V�O���J�A�ߤ������ߡA���U�@�����W
�o�����q����B������C�b�A�}��A���ɶǨӸH�۱������n���A�ݨ�,
���~�����ơA�]�Ϫ��p����w���۶��ݯ}����...
LONG
        );

        set("exits", ([
  "east" : HOLY+"h1",
 "westup" : HOLY+"h3",
        ]) );
        set("light",1);
        setup();
}
