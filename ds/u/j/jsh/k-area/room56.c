inherit ROOM;

void create()
{
        set("short", "�D��");
        set("long", @LONG 
�o�̬O��~���D���A�]�O�g�Ӫ��n�D�A���Ӵ䳣�����~�B�f�����n�g�L�o���D
    ���A�D���W����a����������A��Ǳ�h�h�O�@���A�СC
        [���P�F�_�誺�p��۳s�A�ȥ����u�A�G���}��]
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"northeast" : __DIR__"room56",
  //"west" : __DIR__"room54",
  //"north" : __DIR__"room34",
  "southwest" : __DIR__"room55",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

