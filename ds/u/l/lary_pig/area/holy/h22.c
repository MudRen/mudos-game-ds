#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
���R���P�šB�R���~�D�j�N���۶��A�b�o��ج������ۤ���|�U
�A��Ͼ�Ӹt��Ţ�n�b�@�����������E�u�Ѩ�c�F�A�A�߸̦p�����Q
�ۡA�Q��A�q�L��c�N�i�H���}�t�쪺�������ơA�A���Ѫ��߸��[�t
�B�[�ָ}�B�e�i�C
LONG
        );

        set("exits", ([
  "east" : HOLY+"h23",
 "westup" : HOLY+"h21",
        ]) );
        set("light",1);
        setup();
}
