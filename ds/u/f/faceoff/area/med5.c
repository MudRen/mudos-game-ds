#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"����"NOR);

 set("long",@LONG
�o�̬O���������ݤF, �A���F���|��ѱ�����ݼ��Ӫ���
�ū�, �ӳo�̤��M�O�������Ӫ����a��, �A�i�H�b�o�̧��
�A�һݪ��ħ�.
LONG
    );
 set("exits",([ "east":__DIR__"med6",
		"west":__DIR__"med2",
		"north":__DIR__"med4",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}