#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��l");

 set("long",@LONG
�q�o�̧A�i�H�۷�M�����ݨ���l�����A�Ѱ�, ���Q�U�j
�s���g�[�ä��A�X�ӯѺ�, ���O�b���ѧ@�����O�@�ǨS�������h
�s�U�ʶR�g�a���h�A, �u�n�b���ݯ�....
LONG
    );
 set("exits",([	"south":__DIR__"ten27",
		"north":__DIR__"ten29",
    ]));
 set("objects", ([__DIR__"npc/farmer1" : 3,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}