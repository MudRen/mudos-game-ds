inherit ROOM;
void create()
{
     set("short","�W�E���l�m�߳��y���Űϡz");
      set("long",@LONG
�o�̬O���q�H���׷������A���U�Ӫ��N�n�a�ۤv���V�O�F�I�p�G�A�O
�֦��y�H���Ӫ��ܡA�A�n�b�_�誺�y�W�E�շҤ����z�o���u�ӡA�N��¤U
�@�ӥؼЫe�i�a�I
LONG);
set("exits",([
      "east":__DIR__"8.c",
      "north":__DIR__"13.c",
]) );
set("objects",([
__DIR__"npc/lv14"   :4
]));
        set("world", "future"); 
setup();
replace_program(ROOM); 
}
