#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ����");
 set("long",@LONG
�o��N�O�V����ť�W����R���γ����, �A�i�H�ݨ�
���\�h�Ѷ�B���M�Ӥߪ����U���, �èS���`�N��A�����.
�o��ؤF�@�Ǫ���񪺴Ӫ�, �S���X�جO�A�{�Ѫ�, �o��
�A�{�o���Ӫ��O�X��s��, ���L�O���⪺. �_���٦��@���a
�O�b�s�_������, �����u�ç�u��.
LONG
    );
 set("exits",(["north":__DIR__"garden9",
                "east":__DIR__"garden5",
               "south":__DIR__"inroom8",
                "west":__DIR__"garden8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
