#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�b�q�L��l�c��A�M���`�@�ˡA���e���¬O�@�����ܪ����۶��A
�b�g�L�e���Ʈc�������A�A�`�誺��|��A��ߤμݤO�����n�A�J
�ӷQ�Q�A�o�Ǻ��L��ڪ�����A�����O�i�m�@�ӤH���@�O�̨Τ�k��
�H
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h11",
 "westup" : HOLY+"h13",
        ]) );
        set("light",1);
        setup();
}
