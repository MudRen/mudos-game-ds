#include "path.h"
inherit ROOM;

void create()
{
        set("short", "���l�c");
        set("long", @LONG
���l�c�A�o�O���D�Q�G�c�����A�ܤƳ̦h�A�̥t�H���H���N���P
�y�A�ھڻ��j���ǻ��A���l�y���H�A��@��H��৹����{�X�H����
���M���c���@���A�ҥH�A�Ө�o�઺�H�̰ڡA�A�̤d�U�n�n�۬����A 
�_�h�A���c���u�@�̡A�N�|���A���Ѩ�u�����y�סCù�C�ҡC���z
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h6",
 "westdown" : HOLY+"h8",
        ]) );
        set("light",1);
        setup();
}
