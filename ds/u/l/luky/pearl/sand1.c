// Room: /u/l/luky/sea/sea1.c
#include <path.h>
inherit ROOM;
void create()
{
set("short", "�p�Ѥl");
set("long", @LONG
�o�ӫѤl�Q���U��. �a�W�٦��\�h������C�n��ǨӤ@�}�}�������n..
�A��M�Q�_�q�e�o�̴��g�O�Ӥj�Ӵ�A�i���X�Ӥ�e�j�s�̦b�@�����`����
�ɡA�N��f�������R���F�A�u�ѤU�o����D�����H�C
LONG
);
set("exits", ([ 
  "south" : __DIR__"sand2",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
