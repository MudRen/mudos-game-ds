#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��÷���ȩ��@��(Black Rope Inn)");
        set("long", @LONG
��A�������A���F�·t��A�A�o�{�A���B�b�@�Ӥ����
�O���b���ȩ����A�o�Ӯȩ����C�ӵ��l�W�л\�F�@�h�p�p��
�o�áA���~�����ڥ��L�k�z�i�ӡA�Ӯȩ����ߤ@�o��������
�A�N�O���ӥu�Ѥ@��p���b�̭��N�۪����l�B�M��W�@���I
�۪�����A���ѤF�o�ӳ��˪����ҷL�z���ө��A�ȩ������\
�]�}�¤����B���O�_�I�̭̯d�U���ø�A�ȩ��D�H�@�ƵT��
���ˤl�ݤF�N���H���ΪA�A�Ӧb�·t�������̡A���G���n�X
�����h�n�N���������b���q�ۧA...
LONG
        );
        set("exits", ([ 
                        "north": __DIR__"w1st3",
            ]));
           set("item_desc",([
"����" : "�@�i�����������A�W�����۳\\�h���o�áA���G�٦����V���䤤�H...\n",
"�p���l" : "�@�Ӧb��W���p���l�A�̭��N�ۤ@��L�z���p���A�O�o�ӯ}�®ȩ��̥��G��
�ӷ�...\n"
                 ]));
        set("objects", ([
  __DIR__"npc/brinnkeeper" : 1,
]));

        set("light",1);
        set("no_clean_up", 0);
        setup();
}

