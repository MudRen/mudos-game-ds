#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�n���e�����q�L�d�Ϯc������A�A����b�e�������c�����W�A��
�b�o�شݯ}���۶��W�A�ɺެO���g�ʾԪ��A�A�]�P�쨭�馳�Ǥ��A�C
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h3",
 "westup" : HOLY+"h5",
        ]) );
        set("light",1);
        setup();
}
