#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�g�s��"HIM"��"HIY"�r�s��"NOR);
	set("long", @LONG
    �o�جO�g�s�|�󤧤@ �Сi�r�s��j
�j�y�����u�H���ǧڡA�ڤ��ǤH�v�A�ҥH�g�s���~���㻮���W�n�A
�����򤤡A���O�Ҧ��H���O�o��Q���C�ӯ��s�󪺥D�n�d���A
�N�O�h��(PK)���Ǭ��`�������Ȥ��H�C�ҥH�󤺪�����A�U�H���`�t
�F�`���Z�\�C�������U�j�p�ԧСA�D�n�H�ⳣ�O�Ӧۡi�r�s��j��
�A�ݨ�|�P�u���@�i��l�M���Ʊi�۴ȡA�Ӯ�W�\��F�Ƨ�Q�C�A
�������~�A�S����S�O���B�C   
LONG
	);
	set("exits",([
  "northeast" : __DIR__"dragon.c",
]));
	set("item_desc",([
  "�Q�C" : "�@���W�Q�����C�A���C�٦��Ǧ��¡A�W�������I�`�A�C��X�G���ܦ��F���I\n",
]));
	set("light",1);
set("no_goto",1);
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
	setup();
}
