#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�e�i�B���_���e�i�A�}���񪺡A�̵M�O�L�ɪ�����A�A������A
�]�h�ΡA�w���s�b���󪺪�ı�A�������A����o�̪��A�O�L�񪺰�
�w�N�ӡA�αj�j���n�_�ߡC
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h17",
 "westdown" : HOLY+"h15",
        ]) );
        set("light",1);
        setup();
}
