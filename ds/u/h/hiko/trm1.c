#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"�i"HIY"���ն�"HIW"�j"NOR);
        set("long",
         "�o�̬O�M���Ӵ��ժ��a��A���۳\\�h�ߦ媺�������O�b���ϥ�\n"
         "�b�o�A���A�樫�_�Ӹ����x���A�ӥB�ٯ�ݨ�\\�h��L����Z�A��\n"
         "�ӭn���X�s�@�~�]�O�֪ܲ����A�]�����H��~�P��PĲ�A�ӳo�]�O\n"
         "���Х����b�V�O���A���L�٬O�D�`�����u\n" 
         );
        
set("exits", ([
    "west" : __DIR__"trm2",             ])); 
set("objects",([__DIR__"item/bar-game" : 1,
])); 
setup();
}

