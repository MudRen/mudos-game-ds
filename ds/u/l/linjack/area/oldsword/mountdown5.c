#include <room.h>
inherit ROOM;
void create()
{
 set("short","���s�y�����W");
 set("long",@LONG
�q���}�l�N�O�n�s�����F, �ݰ_�����s���������M���~,
�i�O�o�Q������. �s���Q����Ţ�n��@�b, �s�W�쩳������
�F��A�ݪ����O�Q���M��.
LONG
    );
 set("exits",([ "northwest":__DIR__"mountdown3",
                "west":__DIR__"mountdown4",
		"southeast":__DIR__"mountdown6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}