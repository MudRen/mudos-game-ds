#include <ansi.h>
#include <room.h>
inherit DOOR;
inherit ROOM;

void create()
{
        set("short", RED"�վB��������u�ƶ��n��"NOR);
        set("long", @LONG
�ж����������\�F�@�i�j��l�A�b��l���t�@��a�۴X
��Ȥl�A��W���o�O�A�A�[�W��W���Ƥ����A�����ּƪ�
�����b�o�Ӥ��p���Ŷ��y���F�\�h�̰ʪ����v�A�Ϫ���ө�
�����H�@�س��I�������P�A�A�Ф��ߤ@���X�f���]�N�O�A��
�i�Ӫ��a�衤�ǯ��F��W���ƪZ�˪�ĵ�áA���ﭱ����W��
�ۦu�ƶ����ԺX�A��Ǫ���W�h�U�}�F�@�Ӭ������A�䤤�@
���٬O���}���C
LONG
        );
        set("exits", ([ 
                        "south": __DIR__"ugw2",
            ]));
           set("item_desc",([
"�j��l" : "
�@�i�p�ꪺ�j��l�A�W���J�ۦu�ƶ������O�G�޵P�C\n",
"������1" : "
�@���b�}���������A�@�}�}���D���q��~�j�i�ӡC\n",
"������2" : "
�@���򳬪��������C\n",
"�ԺX" : "
�N��վB��������u�ƶ����ԺX�A��������A�W¸�ۤ@
���V�鸪���r���@���Ŧ��_�ۡC\n",
                 ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        create_door("south","���","north",DOOR_CLOSED);
}

