#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�w�L"NOR);

 set("long",@LONG
�o�̤w�g�O�w�L�����ݤF, �A�i�H�Pı��|�P���ūת��T
�����F�@��, ���O�٬O���\�h���H�a�Ӫ��ͪ��b�o, �A�i�H�b
�o�Ĩ�@�ǧA�n���ħ�.
LONG
    );
 set("exits",([ "east":__DIR__"med14",
		"north":__DIR__"med16",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}