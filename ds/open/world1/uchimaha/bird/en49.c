#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");
 set("long",@LONG
�Aı�o���ǩI�l�x��, �i��o�̪�����b�ӭ��F, 
�A�̦n��@�ӪŮ���M�s���a�觤�U�ӳݤ@�ݮ�, �A�ݨ�
���@�����q�V��n��.

LONG
    );
 
 set("exits",(["southwest":__DIR__"en50",
               "east":__DIR__"en48",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
