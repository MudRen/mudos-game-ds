inherit ROOM;
void create()
{
        set("short", "��s");
        set("long",@LONG
�A�Ө��s�Q���̭����a��A�o�̪K���Z�K���O�B�ѡA�۵M���;�
�D�`���k�A�b�A���e���ۤ@�Ӥs�}�A�̭��ǨӰ}�}�����~�q�n�A��
�ӥi�঳����r�~�b���Ϯ��A���A�P��n�_�C
LONG
        );
  
set("exits", ([
  "enter" : __DIR__"holl",
  "southwest" : __DIR__"mu17",
   ]) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 







