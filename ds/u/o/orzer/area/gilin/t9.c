inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�A�ש��F�ؿv���e���A�A�J�Ӫ��@�@�@���B�W�Ҽg���y�F�۩v�z
�A�~�Q�_�o���N�O���M���Z�����W�������A�u�O�w�g�b����W�����F
�ƤQ�~�A�S�Q�쳺�M�|�b�`�s�O�L���A�]����[�n�_������L�̷|�ש~
���a�A�]�\�Ӷi�h�ݰݡC
LONG
        );
        set("exits", ([
  "southeast" : __DIR__"t8",
  "enter" : __DIR__"lin1",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











