#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ȩШ��D���Y");
 set("long",@LONG
�o�̬O�V����ȩЪ��G��, �W���ݰ_�ӴN����ſ����ˤl,
�ӥB�o��N�n��@�ӨӪ�ż��, ���L�j��ӻ��ٺⰮ�b. �o��
�w�g�O�ȩШ��D�������F, �A���̭��@�I�ݥi�H�ݨ�@�����,
���G�O�ܩФ����Τ���. �n�_���䪺�ж����S�H��. 
LONG
    );
 set("exits",([ "west":__DIR__"inroom33",
               "north":__DIR__"inroom31",
               "south":__DIR__"inroom32",
                "east":__DIR__"inroom27",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
