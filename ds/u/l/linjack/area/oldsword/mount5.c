#include <room.h>
inherit ROOM;
void create()
{
 set("short","���h����");
 set("long",@LONG
�A�J�Ӫ��n�۸}�U���۶�, ���n���A����Ū��ƥ�o��,
�]���q�o��^�U�h, �N�S�R�F. �������¬O�ҽk���M, �A�@
����ߵۤs��, �t�@����ɶq�O������, �קK�ۤv�L�F�X�h.
LONG
    );
 set("exits",([
               "northdown":__DIR__"mount6",
               "eastup":__DIR__"mount4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
