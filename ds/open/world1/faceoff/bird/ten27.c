#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��l");

 set("long",@LONG
�ҿ���l�N�O�b�s�ߤ������a, �ҥH�o�̴N�O�Q�U�j�s����
�@���֦a, ���O�b�䤤�A�Ѫ��A���o���D�`�h�a, �P�ϤT�Ѩ��Y
�N���H�Ӧ��B�Q��.
LONG
    );
 set("exits",([	"southeast":__DIR__"ten26",
		"north":__DIR__"ten28",
		"west":__DIR__"ten32",
    ]));
 set("objects", ([__DIR__"npc/farmer" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}