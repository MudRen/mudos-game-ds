#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ȩШ��D");
 set("long",@LONG
�o�̬O�V����ȩЪ��G��, �W���ݰ_�ӴN����ſ����ˤl,
�ӥB�o��N�n��@�ӨӪ�ż��, ���L�j��ӻ��ٺⰮ�b. �W��
���ȩФj���O�Ū�, �γ\�A�i�H�b�o��p�Τ@�|��. 
LONG
    );
 set("exits",([ "west":__DIR__"inroom30",
               "north":__DIR__"inroom28",
               "south":__DIR__"inroom29",
                "down":__DIR__"inroom16",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
