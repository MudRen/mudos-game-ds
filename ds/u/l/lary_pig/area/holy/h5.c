#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�����c");
        set("long", @LONG
���D�Q�G�c���ĤG�c �w �����c�A�b�o�c���|�P�A��e�ۤ��s��
�v��Ԫ����p�A�b�o�Գ���誺���O�W�A�ݥߵۤ@�Y���j�A�B������
�������A���R�R���[�ݵۤ��ɡC
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h4",
 "westup" : HOLY+"h6",
        ]) );
        set("light",1);
        setup();
}
