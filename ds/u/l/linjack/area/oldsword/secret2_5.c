#include <room.h>
inherit ROOM;
void create()
{
 set("short","�J���f");
 set("long",@LONG
�A���b�o���Pı�쨺��j�C������, ��b���A�P��@�}
���j. �]���A�ݨ쵷�����p�������G���q�_���z�J, �i�O����
�o��j�j�����jŧ���U, �۾����S���Q�}�a, �O�A�P��Q���n
�_.
LONG
    );
 set("exits",([ "east":__DIR__"secret1",
                "west":__DIR__":secret2_3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
