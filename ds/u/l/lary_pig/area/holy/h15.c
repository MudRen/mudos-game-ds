#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�ѯ��c");
        set("long", @LONG
���D�Q�G�c���ĤC�c �w �ѯ��c�A�ѯ��A�U�W��q�A�K�O�u���q
���~���q�O�_���Ū��u��A�ӭ��惡�c�������O�p���A�u�n�A���
���c�u�@�̩ҫ������u�z�����F�쥭�šA��i�q�L�A�_�h�A�N�ԧa�I
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h16",
 "westdown" : HOLY+"h14",
        ]) );
        set("light",1);
        setup();
}
