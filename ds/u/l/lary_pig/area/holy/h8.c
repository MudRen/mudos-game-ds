#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�O�ɤd���U�W�A�`�����h���l�c�u�@�̡A�A�`�`����|��H��
���i�ȤΥi�d�A���l�c�u�@�̪��y�סCù�C�ҡC���z�A�]���A��H
�ͦ��F�s������A�A�P��A�o�@���W�����W�غ�S���նO�A�Q��o
�̡A�A���ѱo�[�ָ}�B�A�V���ɮc�ڶi�C
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h7",
 "westdown" : HOLY+"h9",
        ]) );
        set("light",1);
        setup();
}
