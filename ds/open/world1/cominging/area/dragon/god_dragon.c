#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�g�s��"HIM"��"HIY"���s��"NOR);
	set("long", @LONG
    �o�جO�g�s�|�󤧤@ �Сi���s��j
���󪺥D�n�d���A�N�O�h���U�C���Ū����a���˳�(EQ)�C
�ӥ����`���P���D�h���@�ǰ��Ū��˳�(EQ)���C
�����������h�A�ҥH���˳�(EQ)�]�O�D�`���n���C
�A�ݨ�󤤩񦳳\�h�˳ơA�������~�A�S����S�O���B�C
LONG
	);
	set("exits",([
  "southeast" : __DIR__"dragon.c",
]));
	set("objects", ([ __DIR__"item/weapon_shelf" : 1,
                          __DIR__"item/equip_shelf" : 1,
                          __DIR__"item/item_shelf" : 1, ]));
	set("light",1);
set("no_goto",1);

	setup();
   set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
    replace_program(ROOM);
}
