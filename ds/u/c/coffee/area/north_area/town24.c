#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�����a"NOR);
 set("long",@LONG
�o�̬O�����a�A�j�U�G�m���j��j���A���䪺���W��
�ۤ@�����M�@�]�����A�j�ۥ~�Y�����A���A�Pı�Q�����ΪA
�A�ӧ����N�Q�b�Ȥl�W�A�������Į��E�E�E�E�E

LONG
    );

       set("exits",([
       "south":__DIR__"town21",
           ]));

        set("objects", ([
           ])); 
 set("no_clean_up", 0);
 setup();
 set("light", 1);
}     

