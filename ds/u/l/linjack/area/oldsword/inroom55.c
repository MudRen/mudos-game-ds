#include <room.h>
inherit ROOM;
void create()
{
 set("short","�x�ë�");
 set("long",@LONG
�訫�i�o�̧A�Nı�o���I�`��, �ݨӤ]�ܤ֦��H�ӥ��z
�o���D. �o�䪺���u�N�ܩ��t�F, �A�]�o�I�F�Ӥ���~����
�k�ݲM���o�䪺�@��. �F�䦳������G�ǩǪ�.
LONG
    );
 set("exits",([ "east":__DIR__"inroom61",
                "west":__DIR__"inroom52",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
