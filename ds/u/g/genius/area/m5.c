#include <ansi.h>
inherit ROOM;
void create()
{
set("short","�s��");
 set("long", @LONG
�A���b�@���s���W�A�b�A���䪺�O������ۡA�A��b���������D�W����
��W�C�Ǧ⪺���ۤW�k���۴X������Ӫ��A�i�H����@�Ǥj���Ʀb�W�����C
��v�b�A�����Ƿn�̵ۡA���B�Ǩө_�Ǫ��λ��n�C
LONG
);
set("item_desc",([
]));

set("exits",([
  "southwest":__DIR__"m6",
  "northdown":__DIR__"m4",]));
 set("objects",([
      __DIR__"npc/mantisred" : 1,
 ]));
setup();
}


