inherit ROOM;
void create()
{
        set("short","��}");
        set("long",@LONG
�A�b���O���}�ޤ��e�i�ۡA�o�̥��u�V�ӶV�L�֡A�u��j�j�ݨ�@�I�I
�ƪ��A�}�z���ۤ@�ǩ_�Ǫ��Ÿ��A���G���g������@�ΡA�u�O�{�b�w�g�ॢ
�F�ĪG�A�n���w�g�ܾa��F�A���G�N�b�����B�C
LONG
        );
        set("exits", ([
  "east" : __DIR__"sgn1",
  "west" : __DIR__"sgn3",
]));
        set("no_clean_up", 0);
        set("light",0);
        setup();
        replace_program(ROOM);
}









