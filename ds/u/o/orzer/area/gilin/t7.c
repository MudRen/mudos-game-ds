inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�A����F�˪L�����@���ø��A�q��_�������Pı���G���ۤH�ϩ~��
�A�ݨӴ˪L���ӨëD�O���L�H��A�F�_�h�O�@���p���A�����D�q�����
���L�]�\�i�H���h�ݬݡA��F�o�̤w�g�O�˪L�`�B�F�C
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t10",
  "northwest" : __DIR__"t8",
  "south" : __DIR__"t6",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











