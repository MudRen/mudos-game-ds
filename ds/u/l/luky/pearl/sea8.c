// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "�ըF�a");
set("long", @LONG
�A�����b�@���n�n���F�a�W�C���ۨ���..�A�}�l�o�{�F�y���C����G�V��
�V�Ƿt�F�A�ӥB�ٶ}�l���F�@�Ǥp���Y�C�|�P�٦��ǳ\�����ʹӪ��A���O�ݰ_
�Q������A�i��O�̪񦳤H�ӭװŹL�C
LONG
);
set("exits", ([ 
  "east" : __DIR__"sea7",
  "south" : __DIR__"sea1",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
