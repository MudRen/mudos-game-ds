inherit ROOM;
void create()
{
        set("short", "��s");
        set("long",@LONG
�o�̬O�ݩ��s���a��A�X�G�ݰ_�ӬO���L�H��A�ʪ��]�۷��h
�A�b�A���e���ۤ@�Ǥs���p�ʪ����D�ۡA���A�]�Q��}���h�M���̤@�_
�ը˦b�j�۵M�̡A������G�ǨӰ}�}���~�q�n�C
LONG
        );
  
set("exits", ([
  "southdown" : __DIR__"mu15",
  "eastup" : __DIR__"mu17",
   ]) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 






