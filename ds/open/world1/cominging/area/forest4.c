inherit ROOM;
void create()
{
        set("short", "�˪L���Ŧa");
        set("long",@LONG
�o�̬O�˪L�����Ŧa�A�b�o���_��O�q���B�F�������A�A�ݨ���W
�Ǫ���W�����_�X�X������⪺���Y�A���G�N�O�o�@�a�˪L�����y�H�A
���r�D�A�䨭������񦶡A�ݹL��������H���h�A���F��O�@�Ӥp���A
�ө���n����¬O�˪L, ���䦳�Ӥp�۵P(sign)�C
LONG
        );
        set("exits", ([
  "southwest" : __DIR__"forest5.c",
  "north" : __DIR__"forest3.c",
//  "east" : __DIR__"villagein.c",
]));
        set("item_desc", ([
  "sign" : "�@�ө۵P, �W���g��, '�ױo���ثe�Ȥ��}��, �]�W���a�_�_�a�F��I' \n"
]));
        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

