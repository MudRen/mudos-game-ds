#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D��");

 set("long",@LONG
�o�̬O�D�ު��`�B, �A�ݨ�@�����D�L���b��, �q�e������
�A�i�H�ݥX�e�Q��A���F, ���񳣬O�@��諸�Ͱ�, ���A���H��
�X.
LONG
    );
 set("exits",([	"west":__DIR__"ten33",
    ]));
 set("objects", ([__DIR__"npc/large_viper" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}