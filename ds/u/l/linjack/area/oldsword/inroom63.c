#include <room.h>
inherit ROOM;
void create()
{
 set("short","���U");
 set("long",@LONG
�o��O���U���k�U��, �A�i�H�ݨ줴�M���@��ӤH�b�i��,
���@�Ǩͽä]�b����ݩR. �६�Q�]���}�}�G�G��, ���H�ݤF
�Nı�o�߱��Χ�.
LONG
    );
 set("exits",(["north":__DIR__"inroom66",
                "west":__DIR__"inroom4",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
