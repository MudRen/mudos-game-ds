#include <room.h>
inherit ROOM;
void create()
{
 set("short","�e�U");
 set("long",@LONG
�o��N�O�V���󪺫e�U�F, �A�ݨ���񦳤@�ǯS�O���\���~,
�ݰ_�Ӥ��|�L������, ���L���H�Pı�ܵξA. �A�i�H�ݨ�k�䦳
�ӳq�D�q���Q�����M�Ϋȩ�, �q�`���u�����@�w�a�쪺�H�h����
��. �V����D�����l���b�o�̦��۳B�z�@�Ǩư�, ���L���䪺
���H���L������ۧA, �ݰ_�ӫַܼN���A�@�Ǧ�. �����٦��@��
�q�D, �k���]���@���q�D.
LONG
    );
 set("exits",([ "north":__DIR__"inroom4",
                 "east":__DIR__"inroom17",
                "south":__DIR__"inroom18",
                 "west":__DIR__"inroom40",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
