// road1.c �p��

inherit ROOM;

void create()
{
        set("short", "�p��");
        set("long", @LONG
�o���p���O�x�j���k�H�̥h�K�L�̥��y�ɨ��X�Ӫ��A�A���訫�N����
��t�Ӷi�J�˪L�F�C�����i�Hť�����B�Ǩӳ��~���q�n�A�A�٬O�֦^�h�a�C
LONG
        );

        
        set("exits", ([
            "west" : __DIR__"shanqiu",
            "east" : __DIR__"pmchang",
            
        ]));

        set("outdoors", "land");
        
        setup();
        replace_program(ROOM);
}
