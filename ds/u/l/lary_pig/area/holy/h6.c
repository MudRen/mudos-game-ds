#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�o�O�Ѫ����c�q�����l�c�����W�A�A����e�観�p�L�a�L�ɪ���
��A�A�u�P�즳�I�ᮬ�A������A�n�ӳo���a��C
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h5",
 "westup" : HOLY+"h7",
        ]) );
        set("light",1);
        setup();
}
