inherit ROOM;
void create()
{
        set("short","��}");
        set("long",@LONG
�A���p�߱��i�F���O���}�ޤ��A�o�̤Q�������t�����A�S��k�ݲM���P
�D���ƪ��A���L�}�޲`�B���۩_�Ǫ��q�n�A�����D���ۤ���F��A�[�W���n
�b�}�����^����¶�A��^���O�ܦn�A���H���I�xŸ����C
LONG
        );
        set("exits", ([
  "out" : __DIR__"t5",
  "west" : __DIR__"sgn2",
]));
        set("no_clean_up", 0);
        set("light",0);
        setup();
        replace_program(ROOM);
}









