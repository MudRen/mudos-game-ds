#include "path.h"
inherit ROOM;

void create()
{
        set("short", "���ɮc");
        set("long", @LONG
�o�̬O���D�Q�G�c���ĥ|�c �w ���ɮc�C���Y����ѪšA�A�o�{
�A���ɮy�A�b��ӿ��諸�t�z���A��O�Q���t�H���P�y�A���A�۹諸
�A���Ҵ��o�X�����~�A�o���H�P��L�����ŷx�C
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h8",
 "westup" : HOLY+"h10",
        ]) );
        set("light",1);
        setup();
}
