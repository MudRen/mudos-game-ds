inherit ROOM;
void create()
{
        set("short","���");
        set("long",@LONG
�A�Ө�F��ӳ��ݡA�o�̯��ۤ@�W��۫p���˥Ҫ��H�A���W�y�S�X
�[�g�F�}����աA�L�����M�`���`�N�ۥ_��A���G�b��ߤU�@��N�o��
�F����ơA��W���u�]���褣�����A�ݨ�����O�§ʤ@���r�N�C
LONG
        );
        set("exits", ([
  "down" : __DIR__"m5-3",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}








