#include <room.h>
inherit ROOM;
void create()
{
 set("short","��Τ�");
 set("long",@LONG
�A�Ө�F�@��²������Τ���, �o�Τl���j, �u��e�U�@��
�H����ͬ��_�~�һݭn���Ŷ�. ���M�o�Фl²��, ���O�j��W��
��M��. �Aı�o���I�_��, ��W�������@��Q��ģ�������٩M�@
����}, ���Ӧ��H��b�o, ��W���Ƕ��泺�M�٬O����.
LONG
    );
 set("exits",([ "north":__DIR__"mountroad1_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}