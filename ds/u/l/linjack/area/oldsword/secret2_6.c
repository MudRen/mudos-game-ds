#include <room.h>
inherit ROOM;
void create()
{
 set("short","���Ǥ�");
 set("long",@LONG
�A�g�L�d���U�W���L�{, �`��}�ҤF���o�̪�����, �i�O�@��
�U�ӧA�N�P��@�ѱj�j�L�񪺮�ժﭱŧ��, ��A���o�I�I�L�k�I�l
, �o�ӯ��Ǭݰ_�����ӬO�ӽm�\��. �A���e���M���@�W�w�g���Y�վv
���e�a�Ѫ������H�h, �L���W�Ҵ��o�X�Ӫ��u��G����ӯ���, ���D
�L�N�O.........!?
LONG
    );
 set("exits",([ "up":__DIR__":secret2_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
