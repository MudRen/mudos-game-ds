#include <room.h>
inherit ROOM;
void create()
{
 set("short","�x�ë�");
 set("long",@LONG
���}�F���, �訫�i�o�̧A�Nı�o���I�`��, �ݨӤ]��
�֦��H�ӥ��z�o�ж�. �o�䪺���u�N�ܩ��t�F, �A�]�o�I�F
�Ӥ���~����k�ݲM���o�䪺�@��. ���䦳������G�ǩǪ�.
LONG
    );
 set("exits",([ "east":__DIR__"inroom30",
                "west":__DIR__"inroom61",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
