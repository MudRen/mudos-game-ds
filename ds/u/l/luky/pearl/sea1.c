// Room: /u/l/luky/sea/sea1.c
inherit ROOM;
void create()
{
set("short", "�ըF�a");
set("long", @LONG
�A�����b�@���n�n���F�a�W�A��W�h���C�@�B���d�U�F�@�ӫܲ`���}�L�C
�@�ɲɥզ⪺�F�l���N�L�N�����i�F�A���c�l�A�A���ʧ�c�l��U�Ӹj�b�y��
�A���۸}�j�B�j�B��B�]�C�ӬX���F�ɨϧA�����}ı�o�D�`�κZ�C
LONG
);
set("Env_sector_type","Under_water");
set("hide_exits", ([
  "west" : __DIR__"pearl_0",
]));
set("exits", ([ 
  "north" : __DIR__"sea8",
  "south" : __DIR__"sea2",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
