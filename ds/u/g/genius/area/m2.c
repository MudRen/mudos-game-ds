#include <ansi.h>
inherit ROOM;
void create()
{
set("short","�s��");
 set("long", @LONG
�A���b�@���s���W�A���Ǥ��ɥi�H�ݨ�U�ة_�Ყ��A�O�H�P��L����
��_�C���ɥi���@�ǪQ���������p�����Űʪ��]�L�A�@���۵M����^�A���H
ı�o�o���˪L��b�O�j�a�����O�����礩�C
LONG
);
set("item_desc",([
"flower":"�A���e�Ҩ����O�@�Ǭ��R�����A�������šA�h�O�A�q�����L���C",
]));

set("exits",([
  "eastdown":__DIR__"m1",
  "southwest":__DIR__"m3",]));
 set("objects",([
 ]));
setup();
}
