inherit MOBROOM;
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
  "northeast" : __DIR__"mu18",
  "westdown" : __DIR__"mu16",
   ]) );
  set("chance",50);
        set("mob_amount",1);
        set("mob_object",({
  __DIR__"animal/big-snake",
}) );
       set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 








