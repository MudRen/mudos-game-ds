#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�d�Ϯc");
        set("long", @LONG
���D�Q�G�c���Ĥ@�c �w �d�Ϯc�A�q�o�̩��Ѫű�h�A�X���J��
���]�p, �ϧA�X�Ϧb�j�P�������Ӯg�U�A�]��M�����ݨ�d�Ϯy����
�ơA�ϧA���o���تA�j�H�����z�C
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h2",
 "westup" : HOLY+"h4",
        ]) );
        set("light",1);
        setup();
}
