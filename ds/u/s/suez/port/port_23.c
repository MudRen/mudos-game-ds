#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�ĺ��Ĵ��s��");
        set("long",@LONG
�o�̬O�ĺ��Ĵ��s�����n��A�]�O�ӷ~�j�D���_�Y�C�]���ө��ĺ���
�����H�U�ӷU�h�A�s�س]���שԤj�D�]��K�F�f�����B��A�ҥH���֤H��
�Q�Ӧ��}����~�A���L�]�l�ޤF�@�Ǥ������å�A�ϱo�̪�Ӯa�̾D��
�D�m���ץ�h�X���a�C
LONG 
);
        set("exits",([
            "north":__DIR__"port_19",
            "south":__DIR__"port_25",
                ]));
        set("objects",([
             __DIR__"npc/ad_wm":2,
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
