#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�g��c");
        set("long", @LONG
���D�Q�G�c���ĤE�c �w �g��c�A�g��P�y�A��ϧΩҲզ����A
�O�@�����}�b�A�^�i���H���ګi�h�A�۶ǡA�H���ڡA�U�ӳ��O�ϥ�
�}�b������A�ڶǤ�A��b�N�X���J�ơA�H���ڥ����H�P���þr���X
�A���ƹ�P�_�A�֤]�����D�C
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h20",
 "westdown" : HOLY+"h18",
        ]) );
        set("light",1);
        setup();
}
