inherit ROOM;
void create()
{
     set("short","�W�E���l�m�߳��y���Űϡz");
      set("long",@LONG
�o�̪��ͤƤH�V�ӶV�j�A�����ݥX�ۤv�w�g�֭n��F�G�ű��⪺�\�O
�F�I�A���U���U�h�N�֨�F�շҤ��ҤF�A�u�O�B�B���磫�A���������Ǩ�
�i�Ȫ���|�n....
LONG);
set("exits",([
      "east":__DIR__"7.c",
      "west":__DIR__"9.c",
]) );
set("objects",([
__DIR__"npc/lv13"   :4
]));
        set("world", "future"); 
setup();
replace_program(ROOM); 
}
