#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIR"�ӳ�"HIW"�J�f"NOR);
        set("long", @LONG
�o�̬O�@�B����~�A�~�Ṋ̀������h���_���A���o�u�O�������A�S
�H�i�ҹꪺ�٦��ڤF�ѡA�ܤ[�H�e�A���@�Ӥ��Ȧ����i�h�i�h�A���i�h�F
�X�Ӥ볣�S�X�ӡA�Q���o�̭��t���\�h�_�ΩǪ������~�a!!�٦����঳��
���ª��۸O(stele)�A�j�i�ݬ�!!
LONG
        );

           set("exits", ([ /* sizeof() == 1 */
            "enter" : __DIR__"room2",
            ]));
        set("item_desc",([
         "stele":"�۸O�W�g��: �o�D��a�ӳ��A�S�g��ǡA���\\��J
                  �H�̱��E�E�L�E�E�j�E�E\n",
          ]));
       set("no_clean_up", 0);
        set("light", 1);
       set("valid_startroom",1);

        setup();
        replace_program(ROOM);
}


        
