#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
�q�o�䩹�A�e�誺����h, �i�H�ݨ�@���������u, ���O�o
���u���M�Q�������t, �i��u�O����άO�@�j�οä��Φb�����
�w. �A���M�@��ť�o�쳥�~���s�n, ���A����ı�i�D�A�e���b�A
�����o�����W, �]�������n���ӻ����F.
LONG
    );
 set("exits",([ "west":__DIR__"jungle8",
		"south":__DIR__"jungle6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}