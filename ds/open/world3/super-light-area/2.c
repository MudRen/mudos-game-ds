inherit ROOM;
void create()
{
      set("short","�W�E���l�m�߳��y��Űϡz");
      set("long",@LONG
�o�̬O�A�X��ťͽm�ߪ��a��A�֦��������j�L�׫~��B�¤O���O��
�z���A�H�K���ˤF�O�H�A�i���o�̪��H�u�ʡB�Ӫ��Q�@��S���g�窺�泾
�F���F�@�Ӭ}�B��@�Ӭ}�A���e�N�@�ӷs��t�I���ˤF�w���H��....
LONG);
set("exits",([
     "out":__DIR__"1.c",
      "west":__DIR__"3.c",
     "north":__DIR__"7.c",
       "east":__DIR__"5.c",
]) );
set("objects",(
[__DIR__"npc/lv1_guard" : 4]
) );
        set("world", "future"); 
setup();
replace_program(ROOM);
}
