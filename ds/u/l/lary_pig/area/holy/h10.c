#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
���������q�A�t�A�P��L�����h�ΡA�o������@�q�����U�ӡA�A
���}�]�_�F�\�h�����w�A�b�e�誺�����B�A���ɶǨӰ}�}����q�A�o
���j���q�n�A���ȴN�O��l�c�u�@�̩ҵo�X���C
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h9",
 "westup" : HOLY+"h11",
        ]) );
        set("light",1);
        setup();
}
