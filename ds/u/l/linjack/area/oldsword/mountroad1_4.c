#include <room.h>
inherit ROOM;
void create()
{
 set("short","��Ϊ��~��");
 set("long",@LONG
�A�Ө�o�ۭӳ��D���a��. �Ů𤣿�, �A���U�|�P�o�{��
�n�䦳�@�Ӥp�p�����, ���ӬO�s�����@�Ǿ��ҩҩ~���p��
�l. �A�P�즳�@�ѳ����j��A������, �o���񦳤���_�Ǫ��a
���?
LONG
    );
 set("exits",([ "northeast":__DIR__"grave",
                "south":__DIR__"woodhouse",
                "west":__DIR__"mountroad1_3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}