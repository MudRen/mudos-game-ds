inherit ROOM;
void create()
{
     set("short","�W�E���l�m�߳��y���Űϡz");
      set("long",@LONG
�ڡK�o�̪������H���㪺���~���׸}���@�ˡA�L�̤��u���t�j�A�M
�����u�����l��A�ѰڡI�n�O���̬G�ٵo�_�ƨӡA��B�ö}�j�A��������
�O�O�ܥi�Ȫ��I�I
LONG);
set("exits",([
      "east":__DIR__"11.c",
      "west":__DIR__"7.c",
]) );
set("objects",([
__DIR__"npc/lv11"  :4,
]));
        set("world", "future"); 
setup();
replace_program(ROOM); 
}
