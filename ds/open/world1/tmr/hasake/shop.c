// shop.c ���ħJ�p�� 

inherit ROOM;

void create()
{
        set("short", "���ħJ�p��");
        set("long", @LONG
�o�y�b�O����}�¡A���G�f�n��D�H�N�S�A�׾�L���C�b�O���O��
�F���֪F��A���ֵ��A�a�L�����A�ݨӳo�̬O�Ӥp���~�I�C
LONG);
        set("exits", ([            
            "southwest" : __DIR__"pmchang.c",
        ]));        

        set("objects", ([
                    __DIR__"npc/dealer" : 1,
        ]));
        
        set("current_light", 1);
        set("light", 1);
        set("room_type", "shop");
        set("outdoors", "land");
        
        setup();
        replace_program(ROOM);
}
