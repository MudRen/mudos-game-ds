#include <room.h>
inherit ROOM;
void create()
{
 set("short","��Y�W");
 set("long",@LONG
�A�Ө�F�O�@�ӫܥ��w����Y�W, �����i�H�ݨ�s�}�U���A�a
�b�o���ϩάO���, �]���@�ǳ��ͪ��p�ʪ��b�o�䬡��, �ӥB�o
��Q�����e�s, �O�Aı�o�n���Z��.
LONG
    );
 set("exits",([ "southeast":__DIR__"mountroad2_2",
                "west":__DIR__"mountroad2_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}