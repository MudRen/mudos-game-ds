// majiu.c ���\
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�o�O�Ӥj���סA��_�Ӫ��b�O���Q�h�V���A�̭��C�۴X�ʤ��@���C��
���h�A�o�O�w�w�������A�������X�n�R�s�n�A�ݨӯ��ڪ��������N���T
�����C�@��H���b����M���ץD�H�ӰQ�����A�ݥL�̪��A���n���O�q����
���i���ӨӡC
LONG);
        set("exits", ([
            "west" : __DIR__"caoyuan7",            
        ]));
        set("objects", ([
//                    __DIR__"npc/xiaoxiang" : 1,
        ])); 
        set("outdoors", "land");        
        setup();
        replace_program(ROOM);
}
